#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q;
ll w[500005];
ll D[501][501];
ll G[501][501];
vector<pair<ll,ll>> F[500005];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> P;
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
        cin>>w[i];
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            if(i!=j)
                G[i][j]=D[i][j]=LONG_LONG_MAX;
            else
                G[i][j]=D[i][j]=0;
    for(ll i=1;i<=n;i++) {
        ll k;
        cin>>k;
        for(ll s=1;s<=k;s++) {
            ll a,t;
            cin>>a>>t;
            F[a].push_back({i,t});
        }
    }
    for(ll i=1;i<=m;i++) 
        for(ll x=0;x<F[i].size();x++)
            for(ll y=x+1;y<F[i].size();y++) 
                D[F[i][x].first][F[i][y].first]=D[F[i][y].first][F[i][x].first]=min(D[F[i][y].first][F[i][x].first],F[i][x].second+F[i][y].second);
    for(ll i=1;i<=n;i++) {
        P.push({0,i});
        while(P.size()) {
            ll val=P.top().first,u=P.top().second;
            P.pop();
            if(G[i][u]!=val)
                continue;
            for(ll s=1;s<=n;s++)
                if(D[u][s]!=LONG_LONG_MAX) {
                    if(G[i][u]+D[u][s]<G[i][s]) {
                        G[i][s]=G[i][u]+D[u][s];
                        P.push({G[i][s],s});
                    }
                }
        }
    }
    for(ll i=1;i<=q;i++) {
        ll x,y,res=LONG_LONG_MAX;
        cin>>x>>y;
        for(ll opt0=0;opt0<F[x].size();opt0++) 
            for(ll opt1=0;opt1<F[y].size();opt1++)
                if(G[F[x][opt0].first][F[y][opt1].first]!=LONG_LONG_MAX) 
                    res=min(res,G[F[x][opt0].first][F[y][opt1].first]+F[x][opt0].second+F[y][opt1].second+w[x]+w[y]);
        cout<<res<<'\n';
    }
    return 0;
}