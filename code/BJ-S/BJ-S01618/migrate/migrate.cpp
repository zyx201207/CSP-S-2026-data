#include <bits/stdc++.h>
using namespace std;
long long dp[2000005],f[2000005],n,m,a[2000005],q[2000005],l=1,r=0;
void DP(int p){
    f[p]=1;dp[p]=0;l=1;r=0;
    q[++r]=p;
    for (int i=p+1;i<=n;i++){dp[i]=1e15;f[i]=0;
        while (l<=r && a[i]-a[q[l]]>m) l++;
        if (l>r){dp[i]=1e15;continue;}else dp[i]=dp[q[l]]+1;
        for (int j=l;j<=min(l+2,r);j++){
            if (dp[q[j]]==dp[q[l]]) f[i]+=f[q[j]];
            else break;
        }
        while (l<=r && dp[q[r]]>dp[i]) r--;
        q[++r]=i;
    }
}
void solve(){
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }long long ans=0;
    for (int i=1;i<=n;i++){
        DP(i);
        for (int j=i+1;j<=n;j++){//printf("%d ",dp[j]);
            if (f[j]==2 && dp[j]!=1e15){
                ans++;
            }
        }//printf("\n");
    }printf("%lld",ans);
return ;}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while (t--){
        solve();if (t!=1) printf("\n");
    }fclose(stdin);fclose(stdout);
    return 0;
}
