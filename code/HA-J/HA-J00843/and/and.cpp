#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		int maxx=-1e9;
		for(int i=1;i<=n;i++)
			maxx=max(maxx,a[i]);
		cout<<maxx;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans=(ans&a[i]);
		cout<<ans;
	}
	if(m==2)
	{
		int maxx=-1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
					maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	} 
	return 0;
}
