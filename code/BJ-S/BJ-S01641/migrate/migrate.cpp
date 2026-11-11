#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[2000005],dis[2000005],cnt[2000005];
vector<int> e[2000005];
void bfs(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    dis[s] = 0;
    cnt[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int x = q.front();
        q.pop();
        for (auto i : e[x]) if (dis[i] > dis[x] + 1){
            cnt[i] = cnt[x];
            dis[i] = dis[x] + 1;
            q.push(i);
        }else if (dis[i] == dis[x] + 1) cnt[i] += cnt[x];
    }
}
void solve(){
    cin >> n >> d;
    for (int i = 1;i <= n;i++) cin >> a[i],e[i].clear();
    for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) if (a[j] - a[i] <= d) e[i].push_back(j);
    else break;
    int ans = 0;
    for (int i = 1;i <= n;i++){
        bfs(i);
        for (int j = i + 1;j <= n;j++) if (cnt[j] == 2) ans++;
    }
    cout << ans << "\n";
}
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> T;
    while (T--) solve();
    return 0;
}