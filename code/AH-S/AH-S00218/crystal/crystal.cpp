#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n;
long long m,a[N],b[N];
long long ans=0;
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   scanf("%d%lld",&n,&m);
   for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
   sort(a+1,a+1+n);
   for(int i=1;i<=n;i++)
   a[i]+=a[i-1];
   for(int i=n;i>=1;i--)
   {
	   int l=1,r=i-1;
	   long long x=a[i]-a[i-1];
	   long long sum=0;
	   while(l<=r)
	   {
		   int mid=(l+r)/2;
		   if(x*(i-mid)-a[i-1]+a[mid-1]<=m)
		   {
			   sum=i-mid+1;
			   r=mid-1;
		   }
		   else l=mid+1;
	   }
	   ans=max(ans,sum);
   } 
   printf("%lld",ans);
   return 0;
}
