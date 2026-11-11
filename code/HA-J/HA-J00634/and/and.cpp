#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans=0;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int p=a[i];
		for(int j=i+1;j<=i+m;j++)
		{
			p=p&a[j];
		}
		ans=max(ans,p);
	}
	cout<<ans;
	return 0;
}
