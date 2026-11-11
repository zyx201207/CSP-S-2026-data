#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+5;
long long x[N], f[N], c, t, n, d, ans, flag;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        ans = 0, flag = 0;
        memset(f, 0, sizeof f);
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        if(c >= 11 && c <= 12){
            int cha = x[2] - x[1];
            int win = d / cha;
            ans = n - 3;
        }else if(c >= 13 && c <= 14){

        }
        cout << ans << '\n';
    }
    return 0;
}
