#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=305;

int T,c,x[N],dis[N],vis[N],cnt[N],minn[N],d,n;

struct edge{
    int v,w;
};

vector<edge> g[N];

void dijsktra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));

    priority_queue<pair<int,int>> q;
    q.push({0,s});
    dis[s]=0;
    cnt[s]=1;

    while(!q.empty()){
        int u=q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u]=1;

        for(edge e:g[u]){
            int v=e.v,w=e.w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=1;
                q.push({-dis[v],v});
            }else if(dis[v]==dis[u]+w){
                cnt[v]++;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> T;
    while(T--){
        memset(minn,0x3f,sizeof(minn));

        cin >> n >> d;
        for(int i=1;i<=n;i++) cin >> x[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                if(abs(x[i]-x[j])<=d){
                    g[i].push_back({j,abs(x[i]-x[j])});
                    g[j].push_back({i,abs(x[i]-x[j])});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            dijsktra(i);
            for(int j=1;j<=n;j++) ans+=(cnt[j]==2);
        }
        cout << ans << '\n';
    }
    return 0;
}
//g++ -o migrate migrate.cpp -O2 -std=c++14 -static