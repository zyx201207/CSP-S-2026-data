//GZ-S00346 贵州省凯里市第一中学 何奕歆 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long c,t,n,d;
	for(int tt=0;tt<t;tt++)
	{
		cin>>n>>d;
		long long x[n];bool f[n];
		for(int i=0;i<n;i++)cin>>x[i];
		for(int i=1;i<n;i++)
		{
			if(x[i]-x[i-1]>d||f[i]==0)f[i]=0;
		}
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+2;j<n;j++)
			{
				
			}
		}
	}
	return 0;
}

