#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
using pii=pair<int,int>;
const int N=500+10,M=500000+10;
#define fi first
#define sc second
int mp[N][N],w[M],testcase,n,m,d,q;
vector<pii>vc[M];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>testcase>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            vc[a].pb(pii(i,t));
        }
    }
    memset(mp,0x3f,sizeof(mp));
    for(int i=1;i<=n;i++)mp[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<vc[i].size();j++)for(int k=0;k<j;k++){
            mp[vc[i][j].fi][vc[i][k].fi]=
                mp[vc[i][k].fi][vc[i][j].fi]=
                min(mp[vc[i][k].fi][vc[i][j].fi],vc[i][j].sc+vc[i][k].sc);
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
    }
    for(int i=1;i<=q;i++){
        int x,y,ans=mp[0][0];cin>>x>>y;
        for(int j=0;j<vc[x].size();j++)for(int k=0;k<vc[y].size();k++){
            ans=min(ans,mp[vc[x][j].fi][vc[y][k].fi]+vc[x][j].sc+vc[y][k].sc);
        }cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
