#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10;

int c,n,m,d,q;
int w[N];
struct node{
    int v,w;
};
vector<node> belong[N];
int dist[510][510];

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i) {
        int k;
        cin>>k;
        for(int j=1;j<=k;++j) {
            int a,t;
            cin>>a>>t;
            belong[a].push_back({i,t});
        }
        for(int j=1;j<=n;++j)
            if(i!=j) dist[i][j]=INF;
    }
    for(int i=1;i<=m;++i) {
        for(auto [x,w1]:belong[i]) {
            for(auto [y,w2]:belong[i]) {
                if(x==y) continue;
                dist[x][y]=min(dist[x][y],w1+w2);
                dist[y][x]=min(dist[y][x],w1+w2);
            }
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(j==i) continue;
            for(int p=1;p<=n;++p) {
                if(p==i||p==j) continue;
                dist[j][p]=min(dist[j][p],dist[j][i]+dist[i][p]);
                dist[p][j]=min(dist[p][j],dist[j][i]+dist[i][p]);
            }
        }
    }
    for(int i=1;i<=q;++i) {
        int x,y;
        cin>>x>>y;
        int ans=INF;
        for(auto [from,w1]:belong[x]) {
            for(auto [to,w2]:belong[y]) {
                ans=min(ans,dist[from][to]+w[x]+w[y]+w1+w2);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
