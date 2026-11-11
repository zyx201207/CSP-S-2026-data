#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n,d;
int ans = 0;
void dfs(int now,int res){
    //cout << now << ' ' << res << '\n';
    if(now == n){
        ans++;
        return ;
    }
    if(res <= 0) return ;
    for(int i = now + 1;a[i] - a[now] <= d && i <= n;i++){
        dfs(i,--res);
        res++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        a.assign(n+1,0);
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        int preis = 1;
        int flcnt = 0;
        for(int i = 1;i < n;i++){
            if(a[i + 1] - a[preis] > d){
                flcnt++;
                preis = i;
            }
        }
        flcnt++;
        dfs(1,flcnt);
        cout << ans << '\n';
    }
}
