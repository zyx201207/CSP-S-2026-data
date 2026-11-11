#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,m,d,q,w[maxn];
ll dis[505][505];
vector<pi>v[maxn];
void slv(){
    scanf("%*d%d%d%d%d",&n,&m,&d,&q);
    up(i,1,m)scanf("%d",&w[i]);
    up(i,1,n){
        int k;scanf("%d",&k);
        up(j,1,k){
            int x,y;scanf("%d%d",&x,&y);
            v[x].eb(i,y);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    up(i,1,n)dis[i][i]=0;
    up(i,1,m)for(auto[a,b]:v[i])for(auto[c,d]:v[i])
        dis[a][c]=min(dis[a][c],(ll)b+d);
    up(k,1,n)up(i,1,n)up(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(;q--;){
        int x,y;scanf("%d%d",&x,&y);
        ll res=1e18;
        for(auto[a,b]:v[x])for(auto[c,d]:v[y])
            res=min(res,dis[a][c]+b+d);
        res+=w[x]+w[y];
        printf("%lld\n",res);
    }
}
int main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    slv();
    return 0;
}