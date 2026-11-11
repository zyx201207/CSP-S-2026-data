#include <bits/stdc++.h>//GZ-J00078  威宁自治县牛棚中学  张晨希
using namespace std;
string n,m;
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    string b,c;
    cin >> n >> b >> m >> c;
    if (n==m){
        cout << 1;
        if (b[0]==c[0] && b[1]==c[1]){
            cout << 1;
            if (b[2]<'C' && c[2]<='C'  ||  'D'<b[2] && 'D'<=c[2]  ||  b[2]<='C' && c[2]<'C'  ||  'D'<=b[2] && 'D'<c[2])
            {
                cout << 1;
                if (b[2]-c[2]==1 || c[2]-b[2]==1) cout << 1;
                else cout << 0;
            }
            else cout << 0 <<0;
            }
        else cout << 0 << 0 << 0;
    }
    else{
        cout << 0 << 0 << 0 << 0;
    }
    return 0;
}

