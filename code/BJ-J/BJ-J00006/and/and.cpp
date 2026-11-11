#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9,M = 39;
int a[N];
bool vis[N][M];
int sum[M],pw[M];
bool use[N];
int n,m;
int ans = 0;
void dfs(int shuwei){

    if(shuwei < 0) return;
    if(sum[shuwei] < m){
        if(shuwei == 0) return;
        sum[shuwei - 1] = 0;
        for(int i = 1;i <= n;i++){
            if(!use[i]) continue;
            sum[shuwei - 1] += vis[i][shuwei - 1];
        }
        dfs(shuwei - 1);
        return;
    }
    ans += pw[shuwei];
    if(shuwei == 0) return;
    //cout << shuwei << " " << ans << endl;
    sum[shuwei - 1] = 0;
    for(int i = 1;i <= n;i++){
        if(!use[i]) continue;
        if(vis[i][shuwei] == 1) sum[shuwei - 1] += vis[i][shuwei - 1];
        else use[i] = 0;
    }
    dfs(shuwei - 1);
    return;
}
void solved(){
    pw[0] = 1;
    for(int i = 1;i <= 30;i++) pw[i] = pw[i - 1] * 2;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        int x = a[i],cnt = 0;
        while(x){
            sum[cnt] += x % 2;
            vis[i][cnt++] = x % 2;
            x /= 2;
        }
        use[i] = 1;
    }

    dfs(30);
    cout << ans << endl;

    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int t = 1;
    //cin >> t;
    while(t--) solved();
    return 0;
}
