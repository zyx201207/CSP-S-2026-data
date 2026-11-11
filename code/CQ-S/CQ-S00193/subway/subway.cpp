#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
inline char nc(){
    static char buf[1000005],*p(buf),*q(buf);
    return p==q&&(q=(p=buf)+fread(buf,1,1000000,stdin),p==q)?EOF:*p++;
}
inline ll read(){
    ll res=0,w=1;
    char c=nc();
    while(c<'0'||c>'9') w=(c=='-'?-1:w),c=nc();
    while(c>='0'&&c<='9') res=res*10+c-'0',c=nc();
    return res*w;
}
vector<pair<ll,ll> > has[N];
ll c,n,m,d,q,i,j,k,l,x,y,id,t,w[N],dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    memset(dis,0x3f,sizeof(dis));
    for(i=1;i<=n;i++) dis[i][i]=0;
    for(i=1;i<=m;i++) w[i]=read();
    for(i=1;i<=n;i++){
        k=read();
        for(j=1;j<=k;j++){
            id=read(),t=read();
            for(l=0;l<has[id].size();l++){
                ll val=min(dis[i][has[id][l].first],has[id][l].second+t);
                dis[i][has[id][l].first]=dis[has[id][l].first][i]=val;
            }
            has[id].push_back(make_pair(i,t));
        }
    }
    for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        ll ans=0x3f3f3f3f3f3f3f3f;
        x=read(),y=read();
        for(i=0;i<has[x].size();i++) for(j=0;j<has[y].size();j++) ans=min(ans,dis[has[x][i].first][has[y][j].first]+has[x][i].second+has[y][j].second);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}