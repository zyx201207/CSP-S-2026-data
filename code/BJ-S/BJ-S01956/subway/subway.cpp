#include <bits/stdc++.h>

using namespace std;

inline int read(){
    int f=1,sum=0;
    char c=getchar();
    while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
    return f*sum;
}
int c,n,m,d,q;
int w[500005];
long long dp[505][505];
long long dis[500500][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            dp[i][j]=LLONG_MAX/3;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=LLONG_MAX/4;
        }
    }
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1,k;i<=n;i++){
        k=read();
        for(int j=1,v,w;j<=k;j++){
            v=read();w=read();
            dis[v][i]=w;
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = min(dp[i][j],dis[k][i]+dis[k][j]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    while(q--){
        int x;
        int y;
        x=read();y=read();
        long long ans = LLONG_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans = min(ans,dis[x][i]+dp[i][j]+dis[y][j]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
