#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;//²îµÄ×ÜºÍ 
	for(int l=1,r=1;r<=n;r++)
	{
		sum+=ans[r-1]*(a[r]-a[r-1]);
		while(sum>m)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans[r]=r-l+1;
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,ans[i]);
	}
	cout << maxn << endl;
	return 0;
}
