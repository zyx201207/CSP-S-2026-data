#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e2+10;
const ll maxm=5e5+10;
const ll maxk=25;
const ll fn=1e17+10;
ll c,m,n,d,q,w[maxm],dist[maxn][maxn];
struct station{
    ll line,t;
};
vector <station> vec[maxm];
vector <station> st[maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(ll i=1;i<=m;i++)
        scanf("%lld",w+i);
    for(ll i=1;i<=n;i++){
        ll tmp;
        scanf("%lld",&tmp);
        for(ll j=1;j<=tmp;j++){
            ll a,t;
            scanf("%lld %lld",&a,&t);
            st[i].push_back({a,t});
            vec[a].push_back({i,t});
        }
    }
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=fn;
    for(ll i=1;i<=n;i++){
        for(ll j=0,len=st[i].size();j<len;j++){
            station now=st[i][j];
            for(ll k=0,_len=vec[now.line].size();k<_len;k++){
                station turn=vec[now.line][k];
                if(turn.line==i)
                    continue;
                dist[i][turn.line]=min(dist[i][turn.line],now.t+turn.t);
            }
        }
    }
    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    while(q--){
        ll x,y;
        ll ans=fn;
        scanf("%lld %lld",&x,&y);
        for(ll i=0,len=vec[x].size();i<len;i++){
            for(ll j=0,_len=vec[y].size();j<_len;j++){
                station t1=vec[x][i];
                station t2=vec[y][j];
                ans=min(ans,t1.t+dist[t1.line][t2.line]+t2.t);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
