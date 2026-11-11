#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[5006],ans=0,s[5006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int l;
			if(a[i]<a[j]) 
			{
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
			l=a[i]-a[j];
		}
	}
    return 0;	
} 
