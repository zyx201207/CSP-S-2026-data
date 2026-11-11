#include<bits/stdc++.h> 
using namespace std;

const int MXN = 500005;
typedef long long ll;
ll n, m, doc, sum, ans, a[MXN], f[MXN];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	 	cin >> a[i];	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		f[i] = a[i] - a[i - 1];
	for (int i = n; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			doc = doc * 2 + f[j];
			if (doc > m)
			{
				ans = max(ans, sum);
				break;
			}
			else
			{
				sum++;
			}
		}
		sum = 1, doc = 0;
			
	}
	cout << ans;
	return 0;
}
