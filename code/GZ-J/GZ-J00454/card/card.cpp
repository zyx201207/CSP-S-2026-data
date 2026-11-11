//GZ-J00454 华东师范大学附属贵阳学校 蒋泽赟
#include <bits/stdc++.h>
using namespace std;

int a[500005], b[300005];
int id[300005], ans[300005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(id, 0, sizeof(id));
		memset(b, 0, sizeof(b));
        int cur = 0;
        for (int j = i; j <= n; ++j)
        {
			if (id[a[j]]) cur = id[a[j]];
            else cur++, b[cur] = a[j], id[a[j]] = cur;
        }
        for (int j = 1; j <= cur; ++j)
        {
            ans[b[j]]++;
        }
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << " ";
    return 0;
}
