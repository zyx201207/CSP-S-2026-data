#include<bits/stdc++.h>
using namespace std;
struct edge{
    int v;
    long long w;
};
int n,m;
vector<edge> a[500005];
long long s[500005],dis[505][505];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                dis[i][j]=1e18;
            }
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&s[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int u;
            long long val;
            scanf("%d%lld",&u,&val);
            a[u].push_back({i,val});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:a[i]){
            for(auto k:a[i]){
                if(j.v!=k.v){
                    dis[j.v][k.v]=dis[k.v][j.v]=j.w+k.w;
                }
            }
        }
    }
    floyd();
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        long long minn=1e18;
        for(auto j:a[x]){
            for(auto k:a[y]){
                minn=min(minn,j.w+k.w+dis[j.v][k.v]);
            }
        }
        printf("%lld\n",minn+s[x]+s[y]);
    }
    return 0;
}