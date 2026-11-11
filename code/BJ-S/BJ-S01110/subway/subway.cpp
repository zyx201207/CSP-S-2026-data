#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,q,w[500010],f[514][514],t[514][500010],ans;
bitset<500010>b[514];
vector<int>v[500010];
inline void add(int u,int v,int w){
    f[u][v]=f[v][u]=min(f[u][v],w);
}
signed main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout),
    cin.tie(0)->sync_with_stdio(0),cin>>c>>n>>m>>d>>q,memset(f,0x3f,sizeof f);
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k,f[i][i]=0;
        for(int j=1,a,it;j<=k;j++)
            cin>>a>>it,t[i][a]=it,v[a].push_back(i),b[i].set(a);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            b[0]=b[i]&b[j];
            for(int k=b[0]._Find_first();k<=m;k=b[0]._Find_next(k))
                add(i,j,t[i][k]+t[j][k]);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y,ans=0x3f3f3f3f;
        for(auto j:v[x])
            for(auto k:v[y])
                ans=min(ans,t[j][x]+f[j][k]+t[k][y]);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}