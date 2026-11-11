#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=505;
typedef pair<int,int>pii;
#define fi first
#define se second
vector<pii>p[N];
ll dis[M][M];
int n,m,q,w[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%*d%d%d%*d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)scanf("%d",w+i);
    for(int i=1;i<=n;i++){
        int l;scanf("%d",&l);
        while(l--){
            int x,y;scanf("%d%d",&x,&y);
            p[x].push_back({y,i});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++)for(pii u:p[i])for(pii v:p[i])dis[u.se][v.se]=min(dis[u.se][v.se],(ll)u.fi+v.fi);
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        ll ans=1e18;
        for(pii i:p[x])for(pii j:p[y])ans=min(ans,dis[i.se][j.se]+i.fi+j.fi);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}