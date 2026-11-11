#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m;
int a[N];
bool flag = true;
int value;
int ans;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr), cout.tie(nullptr);
	scanf("%lld%lld", &n, &m);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i = 1; i<=n; i++)
	{
		scanf("%lld", &a[i]);
		if(i<=2)
		{
			value = a[2]-a[1];
			continue;
		}
		if(a[i]-a[i-1]!=value)
			flag = false;
	}
	sort(a+1, a+n+1);
	if(flag)
	{
		int w = value, ans = 2;
		while(w<m)
		{
			ans++;
			if(ans>n)
			{
				ans = n;
				break;
			}
			w+=value*ans;
		}
		printf("%lld", ans);
		return 0;
	}
	for(int i = 1; i<=n; i++)
	{
		int sum = 1, new_m = m;
		for(int j = i-1; j>=1; j--)
		{
			int p = a[i]-a[j];
			if(new_m-p<0)
				break;
			new_m-=p;
			sum++;
		}
		ans = max(ans, sum);
	}
	printf("%lld", ans);
	return 0;
}
