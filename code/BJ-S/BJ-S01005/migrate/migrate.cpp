#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;
int a[MAXN],ru[MAXN],chu[MAXN];
void solve(){
    int n,d; cin >> n >> d;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = n;i >= 1;i--){
        for(int j = i - 1;j >= max(1,i - d);j--){
            ru[j]++;
            chu[i]++;
        }
    }
    for(int i = n;i >= 1;i--) cout << ru[i] << " " << chu[i] << endl;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(abs(ru[i] - chu[i]) <= 1) ans++;
    }
    cout << ans - 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w".stdout);
    int c,t; cin >> c >> t;
    while(t--) solve();
    return 0;
}
