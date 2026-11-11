#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;

int c,m,n,d,q;
ll w[N],k[507],dis[507][507];

struct EDG{
    int v;
    ll w;
};
vector<EDG>e[N];

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        int x;ll y;
        for(int j=1;j<=k[i];j++){
            cin>>x>>y;
            e[x].push_back({i,y});
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            dis[i][j]=1e18;
        }
    }

    for(int i=1;i<=m;i++){
        int dv=e[i].size();
        for(int x=0;x<dv;x++){
            for(int y=x+1;y<dv;y++){
                int u=e[i][x].v,v=e[i][y].v;
                dis[u][v]=min(dis[u][v],e[i][x].w+e[i][y].w);
                dis[v][u]=dis[u][v];
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||i==k||j==k) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    int l,r;
    while(q--){
        cin>>l>>r;
        ll ans=1e18;
        for(int i=0;i<e[l].size();i++){
            for(int j=0;j<e[r].size();j++){
                ans=min(ans,e[l][i].w+e[r][j].w+dis[e[l][i].v][e[r][j].v]);
            }
        }

        cout<<ans+w[l]+w[r]<<'\n';
    }

    return 0;
}
