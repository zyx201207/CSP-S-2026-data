#include <bits/stdc++.h>
using namespace std;

long long s[200005];
long long ans[200005];

bool cmp(long long a, long long b)
{
	return a > b;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++)
	{
		cin >> s[i];
		if(i <= m) ans[i] = s[i];
	}
	sort(ans+1, ans+m+1, cmp);
	long long maxn = ans[1], temp;
	for(int i=2 ; i<=m ; i++)
	{
		maxn &= ans[i];
	}
	
	for(int i=m+1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=m ; j++)
		{
			sort(ans+1, ans+m+1, cmp);
			temp = s[i];
			for(int k=1 ; k<=m ; k++)
			{
				if(k == j) continue;
				temp &= ans[k];
			}
			if(temp > maxn)
			{
				maxn = temp;
				ans[j] = s[i];
				sort(ans+1, ans+m+1, cmp);
			}
		}
	}
	cout << maxn;
	
	return 0;
}
