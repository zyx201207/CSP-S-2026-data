#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long

using namespace std;
ll n,m,a[500005],s[500005];
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   scanf("%lld%lld",&n,&m);
   for(int i=1;i<=n;i++)
     scanf("%lld",&a[i]);
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++)
     s[i]=s[i-1]+a[i];
   ll ans=0;
   for(int i=1;i<=n;i++)
   {
     ll tmp=1,p=m;
     int l=1,r=i-1;
     while(l<=r)
     {
       int mid=(l+r)>>1;
       ll sum=0;
       sum=p-(a[i]*(i-mid)-(s[i-1]-s[mid-1]));
       if(sum==0) {tmp=i-mid+1; break;}
       if(sum>0) r=mid-1,tmp=i-mid+1;
       if(sum<0) l=mid+1;
     }
     while(1)
     {
       if(a[i+1]==a[i]) i++,tmp++;
       else break;
     }
     ans=max(ans,tmp);
   }
   cout<<ans;
   return 0;
}
