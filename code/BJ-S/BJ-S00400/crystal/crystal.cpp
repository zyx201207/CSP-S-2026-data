#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int n,m;
int chk(int mid)
{
   int minn=1e18;
   for(int i=1;i<=n-mid+1;i++)
   {
      int num=0;
      for(int j=i;j<=i+mid-1;j++)
      {
         num+=a[i+mid-1]-a[j];
      }
      minn=min(minn,num);
   }
   return minn;
}
signed main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
   }
   sort(a+1,a+n+1);
   int l=1,r=n;
   while(l<r)
   {
      int mid=(l+r)/2;
      int minn=chk(mid);
      if(minn>m)
      {
         r=mid-1;
      }
      else if(minn<m)
      {
         l=mid+1;
      }
      else
      {
         cout<<mid<<endl;
         return 0;
      }
   }
   if(chk(l)>m) l--;
   cout<<l<<endl;
   return 0;
}
