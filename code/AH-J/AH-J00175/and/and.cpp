#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m;
int a[N],b[N];
long long ans=15,t=0;
int main()
{
   freopen ("and.in","r",stdin);
   freopen ("and.out","w",stdout);
   cin>>n>>m; 
   for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  sort(a+1,a+1+n);
   if(m==2)
   {
	   ans=0;
	   for(int i=1;i<=n;i++)
	    for(int j=i+1;j<=n;j++)
	    {
	   int cmp=a[i]&a[j];
	    if(cmp>ans)ans=cmp;
    }
    return cout<<ans,0;
}
    
  if(m>2)
	{
	for(int i=n;i>=1;i--)
	if((a[i]+1)%8==0 and t<m)
	{
     b[++t]=a[i];
   if(t>=m)break;
    }
   else { 
    for(int i=n;i>=1;i--)
   if((a[i]+2)%8==0 and t<m)
   {
	   b[++t]=a[i];
	   if(t>=m)break;
   }
   }
   for(int i=1;i<=m;i++)ans&=b[i];
   }
   cout<<ans;
  return 0;
  }
