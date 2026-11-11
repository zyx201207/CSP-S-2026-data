#include<iostream>
#include<algorithm>

using namespace std;

long long a[200010];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	bool f = true;
	if(a[n] % 2 == 0)
	{
		int x = a[n];
		for(int i = n; i >= n - m + 1; i -- )
		{
			if(a[i] != x)
			{
				f = false;
				break;
			}
		}
	}
	if(f == true && a[n] % 2 == 0) cout << a[n];
	else
	{
		int pos = -1;
		for(int i = n; i >= 1; i -- )
		{
			if(a[i] % 2 != 0)
			{
				pos = i;
				break;
			}
		}
		if(pos < m) cout << 0;
		else
		{
			long long ans = a[pos];
			for(int i = pos; i >= pos - m + 1; i -- )
			{
				ans &= a[i];
			}
			cout << ans;
		}
	}
	return 0;
}
