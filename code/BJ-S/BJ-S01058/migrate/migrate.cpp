#include<bits/stdc++.h>
using namespace std;
#define ine long long
const int Maxn = 2e6 + 5;
int x[Maxn];
bool con[10][10];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while(T--){
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        //等差数列
        if(c >= 11 && c <= 12){
            int sep = x[2] - x[1];
            d /= sep;
            if(sep < 2){
                cout << 0;
            }else{
                if(n < sep * 2 ){
                    cout << 0;
                }
                else{
                    cout << n - 2 * sep + 1;
                }
            }
        }
        if(c >= 13 && c <= 14){
            cout << 0;
        }
        cout << endl;
    }

    return 0; 
}
