#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=510,M=5e5,INF=0x3f3f3f3f3f3f3f;
ll min_dis[N][N];
ll c,n,m,d,q;
vector<pair<ll,ll>>ttoi[M];
ll dis_tosta[M];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)min_dis[i][j]=0;
            else min_dis[i][j]=INF;
        }
    }
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(min_dis[i][k]!=INF&&min_dis[k][j]!=INF)
                    min_dis[i][j]=min(min_dis[i][k]+min_dis[k][j],min_dis[i][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    init();
    for(int i=1;i<=m;i++)scanf("%lld",&dis_tosta[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            ll to,w;
            scanf("%lld%lld",&to,&w);
            ttoi[to].push_back({i,w});
        }
    }for(int i=1;i<=m;i++){
        for(auto it1:ttoi[i]){
            ll u=it1.first,fr=it1.second;
            for(auto it2:ttoi[i]){
                ll v=it2.first,to=it2.second;
                if(u==v)continue;
                min_dis[u][v]=min(min_dis[u][v],fr+to);
                min_dis[v][u]=min(min_dis[v][u],fr+to);
            }
        }
    }floyd();
    while(q--){
		ll s,e;
		scanf("%lld%lld",&s,&e);
        ll min_to_s=INF;
        for(auto it1:ttoi[s]){
            ll w1=it1.second,u=it1.first;
            for(auto it2:ttoi[e]){
                ll w2=it2.second,v=it2.first;
                ll now=w1+w2+min_dis[u][v];
                min_to_s=min(min_to_s,now);
            }
        }ll ans=min_to_s+dis_tosta[e]+dis_tosta[s];
        printf("%lld\n",ans);
    }
    return 0;
}