#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,int>
#define mk make_pair
const ll inf=0x3f3f3f3f3f3f3f3f;
ll d[505][505],a[500005][25],t[500005][25],len[500005],w[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,D,q;cin>>n>>n>>m>>D>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++){
        int k;cin>>k,d[i][i]=0;
        for(int j=1;j<=k;j++){
            int x,y;cin>>x>>y,a[x][++len[x]]=i,t[x][len[x]]=y;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<len[i];j++)
            for(int k=j+1;k<=len[i];k++) d[a[i][j]][a[i][k]]=d[a[i][k]][a[i][j]]=min(d[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--){
        int x,y;cin>>x>>y;
        ll ans=inf;
        for(int i=1;i<=len[x];i++)
            for(int j=1;j<=len[y];j++) ans=min(ans,t[x][i]+t[y][j]+d[a[x][i]][a[y][j]]);
        cout<<ans+w[y]+w[x]<<'\n';
    }
}