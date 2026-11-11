#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
int x[maxn];
int z[maxn];
int minn[maxn];
int n,d;
void dfs(int now,int last,int summ){
    if (x[now]-x[last] > d || now > n) return;
    if (summ < minn[now]) z[now] = 0;
    else if (summ == minn[now]) z[now]++;
    for (int i = 1;i <= n-now;i++) dfs(now+i,now,summ+1);
    return;
}
void solve(){
    cin >> n >> d;
    for (int i = 1;i <= n;i++) cin >> x[i],z[i] = 0;
    int sum = 0;
    for (int j = 1;j <= n;j++){
        for (int i = 1;i <= n;i++) minn[i] = 99999999;
        dfs(j,j,0);
        for (int i = 1;i <= n;i++) if (z[i] == 2) sum++;
        for (int i = 1;i <= n;i++) z[i] = 0;
    }
    cout << sum << '\n';
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin >> c >> t;
    while (t--) solve();
    return 0;
}
