#include<bits/stdc++.h>

using namespace std;
string a, b;
int x, y, p, q;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> x >> a >> y >> b;
    if(a[2] == 'A' || a[2] == 'B' || a[2] == 'C') p = 0;
    else p = 1;
    if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C') q = 0;
    else q = 1;
    if(x != y){
        cout << "0000" << '\n';
    }else{
        cout << 1;
        if(a[0] != b[0] || a[1] != b[1]){
            cout << "000";
        }else{
            cout << 1;
            if(p != q){
                cout << "00";
            }else{
                cout << 1;
                if(p == 0){
                    if((a[2] == 'A' && b[2] == 'C') || (a[2] == 'C' && b[2] == 'A')) cout << 0;
                    else cout << 1;
                }
                if(p == 1){
                    cout << 1;
                }
            }
        }
    }
    return 0;
}