#include <bits/stdc++.h>
#define pii pair<int,int>
typedef long long LL;
using namespace std;
const int N = 50005;
int c,t;
int n;
LL d;
LL x[N];
priority_queue<pii,vector<pii >,greater<pii > > p;
vector<int> g[N];
bool vis[N];
int dis[N];
long long cnt[N];
void dij(int s) {
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    p.push({0,s});
    dis[s] = 0;
    cnt[s] = 1;
    while(p.size()) {
        int u = p.top().second;
        p.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(int v : g[u]) {

            if(dis[v] == dis[u] + 1) {
                cnt[v] += cnt[u];
            } else if(dis[v] > dis[u] + 1) {
                cnt[v] = cnt[u];
                dis[v] = dis[u] + 1;
                p.push({dis[v],v});
            }
        }
    }
}

void solve() {
    cin >> n >> d;
    for(int i = 0;i < N;i ++) g[i].clear();
    memset(x,0,sizeof x);
    for(int i = 1;i <= n;i ++) {
        cin >> x[i];
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = i + 1;j <= n;j ++) {
            if(x[j] - x[i] <= d) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    long long ans = 0;

    for(int i = 1;i <= n;i ++) {
        dij(i);

        for(int j = i+1;j <= n;j ++) {
     //       cout <<cnt[j] << " ";
            if(cnt[j] == 2) ans ++;
        }
      //  cout <<endl;
    }

    cout << ans << endl;
    return;
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t --)
        solve();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
