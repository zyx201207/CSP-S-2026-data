#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll c,n,m,d,q;
ll x,y;
ll ans;
ll w[500010];
ll k[500010];
map<pair<ll,ll>,ll> vis;
vector<ll> a[510];
vector<ll> t[510];
struct Node{
    ll a,b;
};
vector<Node> p[500010];
void dfs(ll xl,ll djz,ll bh,ll sum,ll mdd){
    if(sum>=ans){
        return;
    }
    if(bh==mdd){
        ans=min(ans,sum+w[y]+t[xl][djz]);
        return;
    }
    for(ll i=djz;i<k[xl];i++){
        if(i!=djz){
            vis[make_pair(xl,i)]=1;
            dfs(xl,i,a[xl][i],sum,mdd);
            vis[make_pair(xl,i)]=0;
        }
        for(Node j:p[a[xl][i]]){
            if(j.a==xl){
                continue;
            }
            if(vis[make_pair(j.a,j.b)]==0){
                vis[make_pair(j.a,j.b)]=1;
                dfs(j.a,j.b,a[xl][i],sum+t[xl][i]+t[j.a][j.b],mdd);
                vis[make_pair(j.a,j.b)]=0;
            }
        }
    }
}
void dfs1(ll xl,ll djz,ll bh,ll sum,ll mdd){
    if(sum>=ans){
        return;
    }
    if(bh==mdd){
        ans=min(ans,sum+w[y]+t[xl][djz]);
        return;
    }
    for(ll i=djz;i<k[xl];i++){
        if(i!=djz){
            vis[make_pair(xl,i)]=1;
            dfs(xl,i,a[xl][i],sum,mdd);
            vis[make_pair(xl,i)]=0;
        }
        for(Node j:p[a[xl][i]]){
            if(j.a==xl){
                continue;
            }
            if(vis[make_pair(j.a,j.b)]==0){
                vis[make_pair(j.a,j.b)]=1;
                dfs(j.a,j.b,a[xl][i],sum+t[xl][i]+t[j.a][j.b],mdd);
                vis[make_pair(j.a,j.b)]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(ll i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(ll i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(ll j=1;j<=k[i];j++){
            scanf("%lld%lld",&x,&y);
            a[i].push_back(x);
            t[i].push_back(y);
            p[x].push_back({i,j-1});
        }
    }
    while(q--){
        ans=0x3f3f3f3f3f3f3f3f;
        scanf("%lld%lld",&x,&y);
        for(Node i:p[x]){
            if(k[i.a]==1){
                continue;
            }
            vis[make_pair(i.a,i.b)]=1;
            dfs(i.a,i.b,x,w[x]+t[i.a][i.b],y);
            vis[make_pair(i.a,i.b)]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
