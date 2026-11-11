#include <bits/stdc++.h>
using namespace std;
long long ans[100005], f[100005], a[200005];
int cnt[100005];
struct node
{
	int L, R;
}b[100005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans[a[i]] = i;
		if (f[a[i]] != 0) 
		{
			cnt[i] = 1;
			cnt[f[a[i]]] = i;
			long long x[100005] = {0}, y = 0;
			for (int j = f[a[i]]; j <= i; j++) 
			{
				if (cnt[j] == false)
				ans[a[j]]--;
				else x[++y] = i;
			}
			for (int j = 1; j <= y; j++) ans[a[j]]--;
		}
		else f[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	cout << "\n";
	
	return 0;
}
