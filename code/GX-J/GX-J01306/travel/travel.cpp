#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int r, x;
    char cr[5], cx[5];
    cin >> r;
    for (int i = 1; i <= 3; i++){
        cin >> cr[i];
    }
    cin >> x;
    for (int i = 1; i <= 3; i++){
        cin >> cx[i];
    }
    if (r == x){
        cout << 1;
        if ((cr[1]==cx[1])&&(cr[2]==cx[2])){
            cout << 1;
            if ((cr[3]=='D'&&cx[3]=='F')||(cr[3]=='F'&&cx[3]=='D')||(cr[3]=='A'&&cx[3]=='B')||(cr[3]=='A'&&cx[3]=='C')||(cr[3]=='B'&&cx[3]=='C')||(cr[3]=='B'&&cx[3]=='A')||(cr[3]=='C'&&cx[3]=='A')||(cr[3]=='C'&&cx[3]=='B')){
                cout << 1;
                if ((cr[3]=='A'&&cx[3]=='C')||(cr[3]=='C'&&cx[3]=='A')){
                    cout << 0;
                }
                else{
                    cout << 1;
                }
            }
            else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
