#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout	);
	int n,ans=0;
	cin>>n;
	char a[n],c[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[n]>>c[n];
	}
	
		for(int i=1;i<=n/2;i++)
		{
			if(a[i]!=a[n+1-i])
			{
				if(a[i]>a[n+-i])
				{
					ans+=a[i]-a[n+1-i];
				}
				else if(a[i]<a[n+1-i])
				{
					ans+=a[n+1-i]-a[i];
				}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			if(c[i]!=c[n+1-i])
			{
				if(c[i]>c[n+-i])
				{
					ans+=a[n+1-i];
				}
				else if(c[i]<c[n+1-i])
				{
					ans+=a[i];
				}
			}	
		}
	
	cout<<ans;
}
