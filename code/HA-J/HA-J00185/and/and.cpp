#include<bits/stdc++.h>
using namespace std;
int a[200020],erk[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	for(int y=1;y<=n;y++)
    {	scanf("%d",&a[y]);
    }
     if(m=1)
     {
     	int ans=0;
     	for(int y=1;y<=n;y++)
     	ans=max(ans,a[y]);
     	cout<<ans;
     	return 0;
	 }
	 else
	 if(m=2)
	 {
	 	int ans=0;
	 	for(int y=1;y<=n;y++)
	 	for(int u=1;u<=n;u++)
	 	{
	 		if(y!=u)
	 		{ans=max(ans,a[y]&a[u]);
		 }
	}
		 return 0;
	 }
	 else 
	 if(n==m)
	 {
	 	int ans=a[1];
	 	for(int y=2;y<=n;y++)
	 	ans=ans&a[y];
	 	cout<<ans;
	 	return 0;
	 }
	 else
	 if(m==n-1)
	 {
	 	int ans=0;
	 	for(int y=2;y<=n;y++)
	 	{int an=a[1];
		 for(int u=1;u<=n;u++)
	 	{
	 		if(u!=y)
	 		an=an&a[u];
	 		
		 }
		 ans=max(ans,an);
	}int an=a[2];
	for(int y=3;y<=n;y++)
	an=an&a[y];
	ans=max(ans,an);
	cout<<ans;
	return 0;
	 }
	 else
	 
	for(int y=0;y<31;y++)
	 if(n==erk[y])
	 {
	 	
	 	sort(a+1,a+n+1);
	 	int ans=a[n];
	 	for(int y=n;y>=n-m+1;y++)
	 	ans=ans&a[y];
	 	return 0;
	 }
    
    else
    {
    
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
	}
	return 0;
}
