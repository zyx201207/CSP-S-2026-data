#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long ll;
const int maxn=505,maxm=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll aw[maxm],dis[maxn][maxn];
typedef pair<int,ll> pr;
vector<pr> G[maxm];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    int ic,in,im,id,iq;
    cin>>ic>>in>>im>>id>>iq;
    rep(i,1,im)scanf("%lld",aw+i);
    rep(i,1,in){
        dis[i][i]=0;
        int ik;
        scanf("%d",&ik);
        rep(j,1,ik){
            int ia;
            ll it;
            scanf("%d %lld",&ia,&it);
            G[ia].emplace_back(i,it);
        }
    }
    rep(i,1,im){
        int sz=G[i].size();
        rep(j,0,sz-1)rep(k,j+1,sz-1){
            int x=G[i][j].first,y=G[i][k].first;
            ll nw=G[i][j].second+G[i][k].second;
            dis[x][y]=dis[y][x]=min(dis[x][y],nw);
        }
    }
    rep(i,1,in)rep(j,1,in)rep(k,1,in)
        dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
    while(iq--){
        int ix,iy;
        scanf("%d %d",&ix,&iy);
        ll ans=inf;
        for(pr &p:G[ix])for(pr &q:G[iy]){
            ans=min(ans,dis[p.first][q.first]+p.second+q.second);
        }
        printf("%lld\n",ans+aw[ix]+aw[iy]);
    }
    return 0;
}