#include<bits/stdc++.h>
using namespace std;
int a[200001],c[200001];
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(n%2==0)
	{
	 for(int i=1;i<=n/2;i++) 
	 {
	    for(int j=n;j>=n/2;j--) 
	   { 
	     if(c[i]!=c[j]) ans=ans+a[j];
	   } 
	 }
	 for(int i=1;i<=n/2;i++) 
	 {
	    for(int j=n;j>=n/2;j--) 
	   { 
	     if(a[i]!=a[j]) 
	     {
			 if(a[j]>a[i])
			 {
				 a[i+1]=a[i+1]-a[j]+a[i];
				 ans=ans+a[j]-a[i];
			 }
			 if(a[j]<a[i])
			 {
				 a[j-1]=a[j-1]+a[j]-a[i];
				 ans=ans-a[j]+a[i];
			 }
		 }
	   } 
	 }
   }
   else
   {
	 for(int i=1;i<=n/2;i++) 
	 {
	    for(int j=n;j>=n/2;j--) 
	   { 
	     if(c[i]!=c[j]) ans=ans+a[j];
	   } 
	 }
	 for(int i=1;i<=n/2;i++) 
	 {
	    for(int j=n;j>=n/2;j--) 
	   { 
	     if(a[i]!=a[j]) 
	     {
			 if(a[j]>a[i])
			 {
				 a[i+1]=a[i+1]-a[j]+a[i];
				 ans=ans+a[j]-a[i];
			 }
			 if(a[j]<a[i])
			 {
				 a[j-1]=a[j-1]+a[j]-a[i];
				 ans=ans-a[j]+a[i];
			 }
		 }
	   } 
	 }
   }
   cout<<ans;
	return 0;
}
