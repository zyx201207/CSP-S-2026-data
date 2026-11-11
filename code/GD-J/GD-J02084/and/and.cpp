#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	int ans;int maxx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			cout<<a[i];
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ans=a[i];
			for(int w=j;w<=m;w++)
			{
				ans&=a[m];
			}
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
}
/*5 3
31 3 1 15 7*/
