#include<bits/stdc++.h>
using namespace std;
 long  long a[100000],sum=0;
 int b[100010];
 long long f[1000010];
int dp [10000][10010];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
    cin>>a[i];
    f[i]=f[i-1]+a[i-1];
   }
     for(int i=1;i<=n;i++){
        b[a[i]]++;
    }
   if(m==0)
    {for(int i=1;i<=n;i++)
    {
        if(b[a[i]]>1)sum+=b[a[i]];
    }
cout<<sum;
  return 0;
     }
for(int i=1;i<=n;i++){
    for(int j=m;j>=1;j--){
        if(f[j]<=m){
    dp[i][j]=max(dp[i][j-f[i]]+1,dp[i-1][j]);
        }
        else{
                dp[i][j]=dp[i-1][j];
    }
}
}
cout<<dp[1][m];
    return 0;

}
