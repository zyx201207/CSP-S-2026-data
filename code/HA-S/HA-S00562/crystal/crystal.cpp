#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
long long n,m,a[N],ans = 1,sum,l = 1,cnt = 1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort (a + 1,a + n + 1);
	sum = a[1];
	for (int i = 2;i <= n;i++)
	{
		sum += a[i];
		cnt++;
		while (sum + m < a[i] * cnt)
		{
			sum -= a[l];
			l++;
			cnt--;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
} 
