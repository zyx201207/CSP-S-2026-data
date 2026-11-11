#include <bits/stdc++.h>
using namespace std;
int n,a[200005],maxn=-1,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int g=a[i];
		for (int j=0;j<m;j++)
		{
			g&=a[i+j];
		}
		maxn=max(g,maxn);
	}
	cout<<maxn;
	return 0;
}
