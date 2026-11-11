#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    string a2,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1==b1){
        cout << 1;
        int p1=(a2[0]-'0')*10+(a2[1]-'0'),p2=(b2[0]-'0')*10+(b2[1]-'0');
        if(p1 == p2){
            cout << 1;
            int anum = a2[2]-'A',bnum = b2[2]-'A';

            if(anum <= 2 && bnum <= 2 || anum >= 3 && bnum >= 3){
                cout << 1;
                if(anum <= 2&&bnum <= 2&&abs(anum-bnum)==1||anum >= 3 && bnum >= 3 && abs(anum-bnum)==2){
                    cout << 1;
                }
                else{
                    cout << 0;
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


