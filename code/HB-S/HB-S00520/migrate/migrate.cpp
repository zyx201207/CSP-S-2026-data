#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define st first
#define nd second
using namespace std;
const int N=2e6+5;
const int INF=0x3f3f3f3f3f3f3f3f;
int n,d;
int x[N],pre[N];
vector<int> e[N];
int dis[N],way[N];

void dijkstra(int s) {
    for(int i=1;i<=n;i++) dis[i]=INF;
    for(int i=1;i<=n;i++) way[i]=0;
    dis[s]=0;
    way[s]=1;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty()) {
        pii now=pq.top();
        pq.pop();
        int d=now.st;
        int u=now.nd;
        if(dis[u]!=d) continue;
        for(int v:e[u]) {
            int w=1;
            if(d+w<dis[v]) {
                dis[v]=d+w;
                way[v]=way[u];
                pq.push({dis[v],v});
            }
            else if(d+w==dis[v]) {
                way[v]+=way[u];
            }
        }
    }
    return ;
}

void solve() {
    cin>>n>>d;
    for(int i=1;i<=n;i++) {
        cin>>x[i];
    }
    pre[0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=pre[i-1];j<=i;j++) {
            if(x[i]-x[j]<=d) {
                pre[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=pre[i];j<i;j++) {
            e[i].push_back(j);
            e[j].push_back(i);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        dijkstra(i);
        for(int j=1;j<=n;j++) {
            if(i!=j&&way[j]==2) {
                ans++;
            }
        }
    }
    cout<<ans/2;
    return ;
}

signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) {
        solve();
        for(int i=1;i<=n;i++) e[i].clear();
        cout<<'\n';
    }
    return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/