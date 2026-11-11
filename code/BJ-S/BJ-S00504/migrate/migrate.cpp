#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pi;
const ll N=5e5+10;
const ll inf=1e18;
ll c,n,m,d,q,ww[N];
ll w[510][510];
vector<ll> g[N];
ll val[510][N];


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>ww[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) w[i][j]=inf;
    }

    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            int a; ll t;
            cin>>a>>t;
            for(int l=0;l<g[a].size();l++){
                w[k][g[a][l]]=w[g[a][l]][k]=min(w[k][g[a][l]],t+val[g[a][l]][a]);
                cout<<t+val[g[a][l]][a]<<" ";
                cout<<w[k][g[a][l]]<<" ";
            }
            val[i][a]=t;
            g[a].push_back(i);
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }

    while(q--){
        int x,y; scanf("%d%d",&x,&y);
        ll ans=inf;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                ll res=val[g[x][i]][x]+val[g[y][j]][y]+w[g[x][i]][g[y][i]];
                ans=min(ans,res);
            }
        }
        ans+=ww[x]+ww[y];
        cout<<ans<<'\n';
    }

    return 0;
}
