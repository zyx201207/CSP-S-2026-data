#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,M=5e5+10;
struct D{ll i,a;};
ll d[N][N],c[M],n,m,q,x,y,k;
vector<D>a[M];
void e(ll &x,ll y){if(y<x) x=y;}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld",&x,&n);
    scanf("%lld%lld",&m,&y);
    scanf("%lld",&q);
    for(ll i=1;i<=m;i++)
    scanf("%lld",&c[i]);
    memset(d,0x3f,sizeof(d));
    for(ll i=1;i<=n;i++){
        scanf("%lld",&k),d[i][i]=0;
        while(k--)
        scanf("%lld%lld",&x,&y),
        a[x].push_back({i,y});
    }
    for(ll t=1;t<=m;t++){
        ll s=a[t].size();
        for(ll i=0;i<s;i++)
        for(ll j=i+1;j<s;j++){
            x=a[t][i].i,y=a[t][j].i;
            k=a[t][i].a+a[t][j].a;
            e(d[x][y],k),e(d[y][x],k);
        }
    }
    for(ll t=1;t<=n;t++)
    for(ll i=1;i<=n;i++)
    for(ll j=1;j<=n;j++)
    e(d[i][j],d[i][t]+d[t][j]);
    while(q--){
        scanf("%lld%lld",&x,&y);
        ll w=1e18;
        for(auto i:a[x])
        for(auto j:a[y])
        e(w,i.a+j.a+d[i.i][j.i]);
        printf("%lld\n",w+c[x]+c[y]);
    }
    return 0;
}