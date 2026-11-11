#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    bool flag = true;
    for(int i = 0; i < c1.size(); i++){
        if(c1[i] != c3[i]){
            flag = false;
        }
    }
    if(flag){
        cout << "1";
        string num1 = "", num2 = "";
        for(int i = 0; i < c2.size(); i++){
            if('0' <= c2[i]&&c2[i] <= '9'){
                num1 += c2[i];
            }
        }
        for(int i = 0; i < c4.size(); i++){
            if('0' <= c4[i]&&c4[i] <= '9'){
                num2 += c4[i];
            }
        }
        for(int i = 0; i < num1.size(); i++){
            if(num1[i] != num2[i]){
                flag = false;
            }
        }
        if(flag){
            cout << "1";
            char pos1 = c2[c2.size() - 1], pos2 = c4[c4.size() - 1];
            if((('A' <= pos1&&pos1 <='C')&&('A' <= pos2&&pos2 <= 'C'))||(('D' <= pos1&&pos1 <= 'F')&&('D' <= pos2&&pos2 <= 'F'))){
                cout << "1";
                if((pos1 == 'A'&&pos2 == 'B')||(pos1 == 'B'&&pos2 == 'A')){
                    cout << "1";
                }else if((pos1 == 'B'&&pos2 == 'C')||(pos1 == 'C'&&pos2 == 'B')){
                    cout << "1";
                }else if((pos1 == 'D'&&pos2 == 'F')||(pos1 == 'F'&&pos2 == 'D')){
                    cout << "1";
                }else{
                    cout << "0";
                }
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}
