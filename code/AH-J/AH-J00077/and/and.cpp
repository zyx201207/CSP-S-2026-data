#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], tong[31];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and5.in", "r", stdin);
    freopen("and.out", "w", stdout);
  
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> bignum, old;
	for (int i = 1; i <= n; i++)
		old.push_back(a[i]);
	for (int j = 30; j >= 0; j--)
	{
		for (int i = 0; i < (int)old.size(); i++)
		{
			int x = old[i];
			if ((x >> j) & 1)
			{
				bignum.push_back(old[i]);
			}
		}
		if ((int)bignum.size() >= m)
		{
			old.clear();
			for (int i = 0; i < (int)bignum.size(); i++)
				old.push_back(bignum[i]);
			bignum.clear();
		}
		else bignum.clear();
	}
	int ans = INT_MAX;
	for (int i = 0; i < (int)old.size(); i++)
		ans &= old[i];
	cout << ans << '\n';
    return 0;
}
