#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500010], ans[500010];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        ans[a[j]]++;
        for (int i = j + 1; i <= n; i++)
        {
            if (a[i] != a[i - 1])
            {
                ans[a[i]]++;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}
