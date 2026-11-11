#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 != b1){
        cout << "0000";
        return 0;
    }
    cout << 1;
    bool a= 1;
    for (int i = 0;i <= 1;i++){
        if (a2[i] != b2[i]){
            a = 0;
        }
    }
    if (a){//1pai
        cout << 1;
        if (a2[2]<='C' && a2[2] >= 'A' && b2[2]<='C' && b2[2] >= 'A'){//1bian
            cout << 1;
            if (abs(a2[2] - b2[2])==1){//xianglin
                cout << 1;
            }
            else cout << 0;
        }
        else if (a2[2]=='D' && b2[2] == 'E' || a2[2]=='E' && b2[2] == 'D'){
            cout << "11";
        }
        else{
            cout << "00";
        }
    }
    else cout << "000";
    return 0;
}
