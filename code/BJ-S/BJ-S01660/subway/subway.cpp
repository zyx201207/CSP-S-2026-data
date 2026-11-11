#include<bits/stdc++.h>
typedef long long ll;
#define gtun getchar_unlocked
#define pll pair<ll,ll>
using namespace std;
struct pt{ll pot,co;}a;
ll c,n,m,d,q,w[500001],k[501],u,v,ans,f[501][501];
vector<pt>tmm[500001];
vector<ll>hv[500001];
vector<pll>g[501];
bool cmp(pt x,pt y){return x.pot<y.pot;}
ll read(){
    ll x=0,f=1;
    char ch=gtun();
    while (ch<'0' || ch>'9'){
        if (ch=='-') f=-1;
        ch=gtun();
    }
    while (ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=gtun();
    }
    return x*f;
}
ll find(ll point,ll line){
    for (ll i=0;i<tmm[point].size();i++)
    if (tmm[point][i].pot==line) return tmm[point][i].co;
}
ll dij(ll x){
    priority_queue<pll,vector<pll>,greater<pll> >pq;
    pq.push(make_pair(0,x));
    while (pq.size()){
        pll cur=pq.top();
        ll cf=cur.first,cs=cur.second;
        pq.pop();
        for (ll i=0;i<g[cs].size();i++){
            pll v=g[cs][i];
            if (f[x][cs]+v.second<=f[x][v.first]){
                f[x][v.first]=f[x][cs]+v.second;
                pq.push(make_pair(f[x][v.first],v.first));
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for (ll i=1;i<=n;++i) for (ll j=1;j<=n;j++) f[i][j]=1e18;
    for (ll i=1;i<=m;++i) w[i]=read();
    for (ll i=1;i<=n;++i){
        k[i]=read();
        for (ll j=1;j<=k[i];++j){
            a.pot=read();
            a.co=read();
            tmm[a.pot].push_back(pt{i,a.co});
            hv[a.pot].push_back(i);
        }
    }
    for (ll i=1;i<=m;++i){
        sort(tmm[i].begin(),tmm[i].end(),cmp);
        sort(hv[i].begin(),hv[i].end());
        for (ll j=0;j<tmm[i].size();++j)
        for (ll k=j+1;k<tmm[i].size();++k){
            pt U=tmm[i][j],V=tmm[i][k];
            f[U.pot][V.pot]=f[V.pot][U.pot]=min(U.co+V.co,f[U.pot][V.pot]);
        }
    }
    for (ll i=1;i<=n;++i)
    for (ll j=i+1;j<=n;++j)
    if (f[i][j]<1e15){
        g[i].push_back(make_pair(j,f[i][j]));
        g[j].push_back(make_pair(i,f[i][j]));
    }
    for (ll i=1;i<=n;++i){
        f[i][i]=0;
        dij(i);
    }
    while (q--){
        u=read(),v=read();
        ans=1e18;
        for (ll i=0;i<hv[u].size();++i)
        for (ll j=0;j<hv[v].size();++j){
            ll line1=hv[u][i],line2=hv[v][j];
            ans=min(ans,find(u,line1)+find(v,line2)+f[line1][line2]);
        }
        printf("%lld\n",ans+w[u]+w[v]);
    }
    return 0;
}
