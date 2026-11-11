#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
using ll=long long;
const int N=5e5+10,M=510;
int tid,n,m,D,q;
int w[N];
vector<pair<int,int>> vec[N];
ll d[M][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>tid>>n>>m>>D>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;cin>>x>>y;
            vec[x].emplace_back(i,y);
        }
    }
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++) d[i][i]=0;
    for(int i=1;i<=m;i++){
        int sz=vec[i].size();
        for(int x=0;x<sz;x++){
            for(int y=0;y<sz;y++){
                if(x==y) continue;
                int s=vec[i][x].fi,st=vec[i][x].se;
                int t=vec[i][y].fi,tt=vec[i][y].se;
                d[s][t]=min(d[s][t],0ll+st+tt);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        ll ans=1e18;
        for(auto S:vec[x]){
            for(auto T:vec[y]){
                ans=min(ans,d[S.fi][T.fi]+S.se+T.se);
            }
        }ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}