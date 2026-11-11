#include<bits/stdc++.h>
using namespace std;
const int N=210000;
long long n,m,a[N],dp[N],t,ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   cin>>n>>m;


   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }
   if(n==m&&m!=1){
     ans=a[1];
     for(int i=2;i<=n;i++)
     {
        ans=ans&a[i];
     }
   cout<<ans;
   return 0;
   }
   if(m==1)
   {
       cout<<0;
       return 0;
   }
    for(int i=m;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i]=max(dp[i],a[i]&a[j]);
        }
       if(m==2) ans=max(ans,dp[i]);
   }

   cout<<ans;
   return 0;
}
