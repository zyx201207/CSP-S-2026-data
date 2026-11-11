#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=1000000;
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
		ans=min(a[i],ans);
	}
	cout<<ans;
	return 0;
}
