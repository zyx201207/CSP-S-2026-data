#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
long long w[10000];
long long k[1000];
long long a[10000][10000];
long long t[10000][10000];
long long dp[1000][1000];
int x[100],y[1000];
int as[1000],ae[1000];
int bs[1000],be[1000];
long long ans=2e18;
char *r="read",*wr="write";
void draw(int d,int e){
    for(int i=e;i<=k[d];i++){
        dp[d][i]=min(dp[d][i],w[a[d][e]]+t[d][e]);
    }
}
void draw1(int d,int e){
    for(int i=e+1;i<=k[d];i++){
        dp[d][i]=min(dp[d][i],dp[d][i-1]);
    }
}
int main(){
    freopen("subway.in",r,stdin);
    freopen("subway.out",wr,stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            dp[i][j]=2e17;
        }
    }
    int p=1,p1=1;
    for(int k1=1;k1<=q;k1++){
        p=1,p1=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x[k1]){
                    as[p]=i;
                    bs[p]=j;
                    p++;
                }
            }
        }
        for(int i=1;i<p;i++){
            draw(as[i],bs[i]);
        }
        int u=-1;
        for(int i=1;i<=n;i++){
            if(i==u+1){
                as[p]=u;
                p++;
            }
            for(int j=1;j<=k[i];j++){
                for(int e=1;e<p;e++){
                    if(i!=as[e] || j<bs[e]){;
                        for(int d=bs[e];d<=k[as[e]];d++){
                            if(a[i][j]==a[as[e]][d]){
                                dp[i][j]=min(dp[i][j],dp[as[e]][d]+t[as[e]][d]+t[i][j]);
                                draw1(i,j);
                                u=i;
                            }
                        }
                    }
                }
            }
        }
        ans=2e18;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
 //               cout<<dp[i][j];
                if(a[i][j]==y[k1]){
                    ans=min(ans,dp[i][j]+w[a[i][j]]+t[i][j]);
                }
            }
  //          cout<<endl;
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                dp[i][j]=2e18;
            }
        }
    }
return 0;
}
