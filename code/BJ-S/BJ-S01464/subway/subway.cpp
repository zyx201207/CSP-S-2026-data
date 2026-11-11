#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;
const int N=505, M=5e5+505;
int C,n,m,D,Q;
int w[M];
struct e_t{ int v; ll w; };
vector<e_t> tr[N+M];
ll dis[N+M];

namespace s1{
    void djstra(int s){
        mem(dis,0x3f);
        struct qnode{
            int u; ll d;
            bool operator<(const qnode &oth) const{
                return d>oth.d;
            }
        };
        priority_queue<qnode> q;
        q.push({s,dis[s]=0});
        while (q.size()){
            qnode cur=q.top();
            q.pop();
            int u=cur.u;
            ll d=cur.d;
            if (d>dis[u])
                continue;
            for (auto nd: tr[u]){
                int v=nd.v;
                ll w=nd.w;
                if (d+w<dis[v]){
                    q.push({v,dis[v]=d+w});
                }
            }
        }
    }

    void solve(){
        for (int i=1; i<=Q; i++){
            int x,y;
            cin>>x>>y;
            djstra(x);
            ll ans=(ll)dis[y]+w[x]+w[y];
            cout<<ans<<"\n";
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>C>>n>>m>>D>>Q;
    for (int i=1; i<=m; i++){
        cin>>w[i];
    }
    for (int i=1; i<=n; i++){
        int k;
        cin>>k;
        for (int j=1; j<=k; j++){
            int v,t;
            cin>>v>>t;
            tr[m+i].push_back({v,t});
            tr[v].push_back({m+i,t});
        }
    }
    // if (m<=1000){
        s1::solve();
        exit(0);
    // }
    return 0;
}