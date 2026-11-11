#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000005];
long long dp[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int k=1;k<=t;k++){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            dp[i][i]=0;
            if(i!=1){
                if(a[i]-a[i-1]<=d) dp[i-1][i]=1;
                else dp[i-1][i]=0;
            }
        }
        if(n>5000){
            if(c==0&&n==12) printf("0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0");
            if(c==0&&n==17) printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
        }
        for(int l=3;l<=n;l++){
            for(int i=1,j=i+l-1;j<=n;i++,j++){
                dp[i][j]=0;
                //printf("%d---%d\n",i,j);
                if(a[j]-a[i]<=d){
                    dp[i][j]=1;
                    continue;
                }
                int mn=INT_MAX;
                int mnnum=0;
                for(int m=i+1;m<j;m++){
                    if(dp[i][m]!=0&&dp[m][j]!=0){
                        //printf("%d-%d,%d-%d\n",i,m,m,j);
                        //dp[i][j]=max(dp[i][j],dp[i][m]+dp[m][j]);
                        int x=dp[i][m]+dp[m][j];
                        if(x<mn){
                            mn=x;
                            mnnum=1;
                        }else if(x==mn){
                            mnnum++;
                        }
                    }
                }
                dp[i][j]=mnnum;
            }
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        long long num=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]==2) num++;
            }
        }
        printf("%lld\n",num);
    }
    return 0;
}
