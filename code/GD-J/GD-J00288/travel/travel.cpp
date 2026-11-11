#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn = 100005;

signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a, b, x, y;
    char xx, yy;
    cin >> a >> b >> xx >> x >> y >> yy;
    // cout << a << ' ' << b << ' ' << xx << ' ' << x << ' ' << y << ' ' << yy << endl;
    if(a == x){
        cout << 1;
        if(b == y){
            cout << 1;
            if((xx < 'D' && yy < 'D') || (xx > 'C' && yy > 'C')){
                cout << 1;
                if(xx < 'D'){
                    if(abs(xx - yy) == 1) cout << 1;
                    else cout << 0;
                }else cout << 1;
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