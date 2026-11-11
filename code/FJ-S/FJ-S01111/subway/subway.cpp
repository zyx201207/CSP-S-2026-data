#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=503,M=5e5+3;
const ll inf=2e18;
int oc,n,m,di,q,ki[N];
ll w[M],d[N][N];
vector<int>b[M];
unordered_map<int,int>mp;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>oc>>n>>m>>di>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)d[i][j]=(i==j?0ll:inf);
        cin>>ki[i];
        for(int j=1;j<=ki[i];j++){
            int x,xt;cin>>x>>xt;
            b[x].push_back(i);mp[x*N+i]=xt;
        }
    }
    for(int i=1;i<=m;i++){
        int bi=b[i].size();
        for(int ui=0;ui<bi;ui++)for(int vi=ui+1;vi<bi;vi++){
            int u=b[i][ui],v=b[i][vi];
            d[u][v]=d[v][u]=min(d[u][v],ll(mp[i*N+u]+mp[i*N+v]));
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--){
        int x,y;cin>>x>>y;ll s=inf;
        for(int u:b[x])for(int v:b[y])
            s=min(s,d[u][v]+mp[x*N+u]+mp[y*N+v]);
        cout<<s+w[x]+w[y]<<'\n';
    }
    return 0;
}