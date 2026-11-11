#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int a[N], ans[M], wz[M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> cards;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= m; i++)
			wz[i] = 0;
		cards.clear();
		for (int i = k; i <= n; i++)
		{
			if (wz[a[i]] == 0)
			{
				cards.push_back(a[i]);
				wz[a[i]] = cards.size();
			}
			else
			{
				for (int j = wz[a[i]]; j <= (int)cards.size(); j++)
					wz[cards[j]] = 0;
				auto it = cards.begin() + wz[a[i]];
				cards.erase(it, cards.end());
				wz[a[i]] = cards.size();
			}
		}
		for (int j = 0; j < (int)cards.size(); j++)
			ans[cards[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
    return 0;
}
