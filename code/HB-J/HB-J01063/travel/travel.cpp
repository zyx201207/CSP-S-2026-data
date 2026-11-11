#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string trR, stR, trX, stX;
    cin >> trR >> stR >> trX >> stX;

    int R = stR[2] - 'a', X = stX[2] - 'a';
    if(trR[0] == trX[0] && trR[1] == trX[1]){
        cout << '1';
        if(stR[0] == stX[0] && stR[1] == stX[1]){
            cout << '1';
            if((R <= 2 && X <=2) || (R >= 3 && X >= 3)){
                cout << '1';
                cout << (abs(R - X) == 1);
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
