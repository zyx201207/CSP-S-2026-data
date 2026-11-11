#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010];
int dp[5010][5010];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<n;i++)
            if(a[i+1]-a[i]<=d) dp[i][i+1]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                int k=j+i-1;
                for(int l=j+1;l<k;l++)
                    if(a[l]-a[j]<=d&&a[k]-a[l]<=d)
                        dp[j][k]+=dp[j][l]*dp[l][k];
                if(dp[j][k]==2) ans++;
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}
