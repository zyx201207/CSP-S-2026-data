#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	string b[n];
	long long ans;
	for (int i = 0;i < n;i ++)
	{
		cin >> a[i] >> b[i];
		ans += a[i];
	}
	for (int i = 0;i < n;i ++)
	{
		if (a[i] != a[n - i])
		{
			cout << ans;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
