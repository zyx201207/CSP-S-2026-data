#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,a3,a4;
    string b1,b2;
    cin >> a1 >> a2 >> a3 >> a4;
    if(a1==a3){
        cout << 1;
        if(a2[0] == a2[0] && a2[1]==a4[1]){
            cout << 1;
            if(a2[2] == 'A' && a4[2] == 'B'){
                cout << 11;
            }
            else if(a2[2] == 'A' && a4[2] == 'C'){
                cout << 10;
            }
            else if(a2[2] == 'B' && a4[2] == 'A'){
                cout << 11;
            }
            else if(a2[2] == 'B' && a4[2] == 'C'){
                cout << 11;
            }
            else if(a2[2] == 'C' && a4[2] == 'A'){
                cout << 10;
            }
            else if(a2[2] == 'C' && a4[2] == 'B'){
                cout << 11;
            }
            else if(a2[2] == 'F' && a4[2] == 'D'){
                cout << 11;
            }
            else if(a2[2] == 'D' && a4[2] == 'D'){
                cout << 11;
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
        cout <<"0000";
    }
    return 0;
}
