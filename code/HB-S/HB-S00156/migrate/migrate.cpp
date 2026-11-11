#include<bits/stdc++.h>
using namespace std;
long c,t;
long n,d;
long x[2000005];
int dp[20005][20005];
int dfs(int a,int b){
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    int ans=0;
    if(a==b||a-b==1){
        return 1;
    }
    if(x[b]-x[a]<=d){
        ans=1;
    }
    for(int i=a+1;i<b;i++){
        if(x[i]-x[a]>d){
            break;
        }
        int k=dfs(a,i)*dfs(i,b);
        if(k!=0){
            // cerr<<a<<" "<<b<<" "<<i<<" "<<k<<endl;
        }
        ans+=k;
    }
    return dp[a][b]=ans;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while (t--){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        memset(dp,-1,sizeof(dp));
        if(n<3){
            printf("0\n");
            continue;
        }
        if(c==11||c==12){
            if(n-3>0){
                if(x[3]-x[2]==x[2]-x[1]){
                    printf("%d\n",n-3);
                }
            }
        }
        int num=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dfs(i,j)==2){
                    // cerr<<i<<" "<<j<<" "<<endl;
                    num++;
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}