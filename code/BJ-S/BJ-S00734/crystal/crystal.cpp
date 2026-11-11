#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,k;
int a[500005];
bool cmp(long long a,long long b)
{
	return a < b;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	ans = n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	int p = a[n];
	for(int i = 1;i <= n;i++)
	{
		if(a[i] < p)
		{
			k += p - a[i];
		}
	}
	while(k > m)
	{
		k -= (a[ans] - a[ans - 1]) * (ans - 1);
		ans--;
	}
	cout << ans;
	return 0;
}
