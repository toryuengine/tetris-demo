#include <iostream>
#include <array>
#include <vector>
#include <string>

#include <conio.h>
#include <windows.h>



//tミノを定義
std::vector<std::vector<int>> tmino = {
    {1, 1, 1},
    {0, 1, 0}
};

//iミノを定義
std::vector<std::vector<int>> imino = {
    {1, 1, 1, 1},
};

std::string input;
int ch;
int arrow;



//テトリスのフィールドを作成する
std::vector<std::vector<int>> createfield() {
    int h = 20; //高さの定義
    int w = 10; //横幅の定義
    std::vector<std::vector<int>> arr = {};//配列の定義    

    for(int i = 0; i < h; i++) {
        arr.push_back({});
        for(int t = 0; t < w; t++) {
            arr[i].push_back(0);
        }
    }
        return arr;
}



std::vector<std::vector<int>> input_mino(std::vector<std::vector<int>> field, std::vector<std::vector<int>> mino, int stpoint) {
    //フィールドの初期化
    std::vector<std::vector<int>> arr = createfield();

    //スクリーンにミノを入れ込む
    for(int i = 0; i < mino.size(); i++) {
        for (int j = 0; j < mino[i].size(); j++) {
            // int m = 3 +j;
            arr[i][stpoint] = mino[i][j];
        }
    }
    return arr;
}

int drawscreen(const std::vector<std::vector<int>> arr) {
    for (int k = 0; k < arr.size(); k++) {
        for (int j = 0; j < arr[k].size(); j++) {
            std::cout << arr[k][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}




int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    std::cout << "値: " << ch << "\n"; 

    
    std::cout << "値2: " << arrow << "\n"; 




    int stpoint = 3;//ミノ落下時の開始ポイント
    std::vector<std::vector<int>> arr;

    while(true) {
        ch = _getch();
        if(ch == 224) {
            arrow = _getch();
            if (arrow == 72){
                //上ボタンが押されました
                std::cout << "上ボタンが押されました";

            }else if (arrow == 77){
                //右ボタンが押されました
                stpoint +=1;
                arr = createfield();
                arr = input_mino(arr, tmino, stpoint);
                int result = drawscreen(arr);
                std::cout << "右ボタンが押されました";

            }else if (arrow == 80) {
                //下ボタン押されました
                std::cout << "下ボタンが押されました";

            }else if (arrow == 75){
                //左ボタンが押されました7
                stpoint -=1;
                arr = createfield();
                arr = input_mino(arr, tmino, stpoint);
                
                std::cout << "右ボタンが押されました";
            }  
        }
    }


    // for(int i = 0; i < h; i++) {
    //     arr.push_back({});
    //     for(int t = 0; t < w; t++) {
    //         arr[i].push_back(0);




}