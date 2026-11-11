#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N], cf[N], resu[N];
queue<int> k; 
long long n, m;
bool check(int st, int ed)
{
	return resu[ed] - ((a[ed] - a[1]) * (st - 1) - cf[st - 1]) <= m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		cf[i] = a[i] - a[1] + cf[i - 1];
		resu[i] = (a[i] - a[i - 1]) * (i - 1) + resu[i - 1]; 
	}
	a[0] = a[1];
	long long ans = 1;
	for(int i = 1; i <= n; i++)
	{
		int l = i, r = n;
		while(l < r - 1)
		{
			int mid = (l + r) >> 1;
			if(check(i, mid))
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		ans = max(l - i + 1LL, ans);
	}
	cout<<ans;
	return 0;
}
