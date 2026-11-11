#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n;
long long a[N], m, ans = 1;
//map <long long, int> mp;
//vector <long long> ve;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	//cout << n << "\n";
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		//mp[a[i]] ++;
	}
	sort(a + 1, a + 1 + n);
	/*for(int i = 1; i <= n; i ++)
	{
		if(!ve.empty())
		{
			if(a[i] == ve[ve.size() - 1])
			{
				continue;
			}
			else
			{
				ve.push_back(a[i]);
			}
		}
		else
		{
			ve.push_back(a[i]);
		}
	}
	for(int i = 0; i < (int) ve.size(); i ++)
	{
		cout << ve[i] << " " << mp[ve[i]] << "\n";
	}*/
	int c = m;
	for(int i = n - 1; i >= 1; i --)
	{
		if(ans * (a[i + 1] - a[i]) <= m)
		{
			m -= ans * (a[i + 1] - a[i]);
			ans ++;
		}
		else
		{
			break;
		}
	}
	long long an = 1;
	for(int i = 2; i <= n; i ++)
	{
		if(ans * (a[i] - a[i - 1]) <= m)
		{
			m -= ans * (a[i] - a[i - 1]);
			ans ++;
		}
		else
		{
			break;
		}
	}
	if(ans < an)
	{
		ans = an;
	}
	cout << ans;
	return 0;
}
