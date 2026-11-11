#include<bits/stdc++.h>
using namespace std;

long long a[500005] = {};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int ans = 1;
	for(int i = 1;i <= n;i++)
	{
		int cnt = 1;
		long long up = m;
		for(int j = i - 1;j >= 1;j--)
		{
			up -= a[i] - a[j];
			if(up < 0)
			{
				break;
			}
			cnt++;
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}
