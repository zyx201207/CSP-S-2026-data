#include<cstdio>
#include<vector>
using namespace std;
#define N 502
#define M 500005
int C,n,m,d,q;
int w[M];
long long dis[N][N];
pair<int,int>G[M][21];
int siz[M];
long long min(long long a,long long b){return a<b?a:b;}
char in;
void read(int&x){
    do in=getchar();
    while(in<'0');
    x=in-'0',in=getchar();
    while(in>='0') x=x*10+in-'0',in=getchar();
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int c=0;c<N;c++) for(int i=0;i<N;i++) dis[c][i]=0x3f3f3f3f3f3f3f3f;
    for(int c=0;c<N;c++) dis[c][c]=0;
    read(C),read(n),read(m),read(d),read(q);
    for(int c=1;c<=m;c++) read(w[c]);
    for(int c=1,k,a,t;c<=n;c++){
        read(k);
        for(int i=0;i<k;i++){
            read(a),read(t);
            G[a][siz[a]++]={c,t};
        }
    }
    // return 0;
    for(int c=1;c<=m;c++){
        for(int i=siz[c]-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                int u=G[c][i].first,v=G[c][j].first,w=G[c][i].second+G[c][j].second;
                if(dis[u][v]>w) dis[u][v]=dis[v][u]=w;
            }
        }
    }
    for(int c=1;c<=n;c++){
        for(int i=c+1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(dis[c][i]>dis[c][k]+dis[k][i]) dis[c][i]=dis[i][c]=dis[c][k]+dis[k][i];
            }
        }
    }
    for(int c=0,x,y;c<q;c++){
        long long ans=0x3f3f3f3f3f3f3f3f;
        read(x),read(y);
        for(int i=siz[x]-1;i>=0;i--){
            for(int j=siz[y]-1;j>=0;j--){
                // printf("3:%lld %d %d\n",dis[G[x][i].first][G[y][j].first],G[x][i].second,G[y][j].second);
                ans=min(ans,dis[G[x][i].first][G[y][j].first]+G[x][i].second+G[y][j].second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}