#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2000010];
	cin>>n>>m;
	int maxx=1000005;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			maxx=max(maxx,(a[i]&a[j]));
		}
	}
	cout<<maxx;
	return 0;
}
