#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,ans=1;
long long m,a[500010],s[500010];
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   cin>>n;  
   cin>>m;
   if(m==0){
	 cout<<1;
	 return 0;
   }
   for(int i=1;i<=n;i++)
     cin>>a[i];
   sort(a+1,a+n+1);
   s[1]=a[1];
   for(int i=2;i<=n;i++)
   {
	   s[i]=s[i-1]+a[i];
	   int L=1,R=i,mid;
	    while(R-L>1){
		  if(L==R)  break;
		  mid=(L+R)/2;
		  if(mid*a[i]+s[i-mid-1]-s[i-1]>m)  L=mid;
		  else if(mid*a[i]+s[i-mid-1]-s[i-1]<=m)  R=mid;
	     }
       ans=max(ans,i-mid+2);  
	}
   cout<<ans;
   return 0;
}
