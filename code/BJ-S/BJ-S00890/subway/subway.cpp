#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10,Q=1e5+10;
int c,n,m,d,q;
int w[M];
struct node{
    int to,val;
};
vector<node>v[N+M];
long long inf=1e17,dp[N][N],res;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;++i){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;++j){
            int a,t;
            scanf("%d%d",&a,&t);
            v[m+i].push_back({a,t});
            v[a].push_back({m+i,t});
        }
    }
    for(int i=m+1;i<=m+n;++i){
        for(int j=m+1;j<=m+n;++j){
            if(i==j){
                dp[i-m][j-m]=0;
                continue;
            }
            dp[i-m][j-m]=inf;
        }
    }
    for(int i=m+1;i<=m+n+1;++i){
        for(int j=0;j<v[i].size();++j){
            int x=v[i][j].to;
            long long val=v[i][j].val;
            for(int k=0;k<v[x].size();++k){
                int y=v[x][k].to;
                long long yval=val+v[x][k].val;
                dp[i-m][y-m]=min(dp[i-m][y-m],yval);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=1;i<=q;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        res=inf;
        for(int A=0;A<v[x].size();++A){
            for(int B=0;B<v[y].size();++B){
                int C=v[x][A].to,D=v[y][B].to;
                res=min(res,dp[C-m][D-m]+v[x][A].val+v[y][B].val+w[x]+w[y]);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
