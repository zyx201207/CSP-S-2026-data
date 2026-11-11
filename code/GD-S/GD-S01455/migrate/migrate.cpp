#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn=2e6+5;
int n,d,a[maxn],dis[maxn];
pii pre[maxn];
bool vis[maxn];
unordered_map<int,bool> ban;
vector<pii> g[maxn];
queue<int> q;
void bfs(int s) {
    for (int i=1;i<=n;i++)
        vis[i]=false,dis[i]=1e18,pre[i]={0,0};
    q.push(s),dis[s]=0;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (auto [v,id]:g[u]) {
            if (ban[id]) continue;
            if (dis[u]+1<dis[v]) {
                dis[v]=dis[u]+1;
                pre[v]={u,id};
                q.push(v);
            }
        }
    }
}
void solve() {
    cin>>n>>d;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int cnt=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j && abs(a[i]-a[j])<=d) g[i].push_back({j,++cnt});
    int ans=0;
    for (int s=1;s<=n;s++) {
        for (int t=s+1;t<=n;t++) {
            ban.clear();
            int cnt=0;
            int mn=0;
            while (true) {
                // cout<<s<<endl;
                bfs(s);
                // cout<<"--------"<<endl;
                // cout<<s<<" "<<t<<" "<<dis[t]<<'\n';
                if (dis[t]>1e18) break;
                if (cnt>2) break;
                if (cnt==0) mn=dis[t];
                if (dis[t]==mn) {
                    cnt++;
                    if (cnt>2) break; 
                    int cur=t;
                    // vector<int> path;
                    while (cur!=0 && cur!=s) {
                        // cout<<cur<<" "<<pre[cur].first<<" "<<pre[cur].second<<'\n';
                        // cout<<pre[cur].second<<" ";
                        ban[pre[cur].second]=true;
                        // path.push_back(cur);
                        cur=pre[cur].first;
                    }
                    // for (int i=path.size()-1;i>=0;i--)
                    //     cout<<path[i]<<" ";
                    // cout<<'\n';
                }
                else break;
                
            }
            if (cnt==2) /*cout<<s<<" "<<t<<"\n",*/ans++;
        }
    }
    cout<<ans<<'\n';
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while (T--)
        solve();
    return 0;
}
