#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
map<long long,long long>r;
long long a[500200];
long long ans;
long long oo[500200];
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
	{
		long long t;
		scanf("%lld",&t);
		if(r[t]==0)
		{
			 ans++;
			 a[ans]=t;
		}
	       r[t]++;
	 } 
     sort(a+1,a+ans+1);
     oo[0]=0;
     int u=1;
     if(ans!=n)u=0;
     for(int i=1;i<=ans;i++)
	 {
	 	if(i>=3&&ans==n)
	 	{
	 		if(a[i]-a[i-1]!=a[i-1]-a[i-2])u=0;
		 }
	 	oo[i]=r[a[i]]+oo[i-1];
	  } 
     long long sum=0;
     for(int i=1;i<ans;i++)
     {
     	long long e=0;
     	for(int j=i+1;j<=ans;j++)
		 {
		 	e+=abs(oo[j-1]-oo[i-1])*(a[j]-a[j-1]);
		 	if((e<=m)&&(abs(oo[j]-oo[i-1])>=sum))
			 {
			 	sum=abs(oo[j]-oo[i-1]);
			 }
		 	if(e>m)break;
		} 
		if(i==1&&u==1)break;
	 }
	 printf("%lld",sum);
	return 0;
} 
