#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=1,maxx;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==m)
	{
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==2)
	{
		maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
			if(i==j)
			{
				continue;
			}
			maxx=max(maxx,(a[i]&a[j]));	
			}
		}
		cout<<maxx;
	 	return 0;
	}
}
