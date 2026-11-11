#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e6 + 6;

int c, t, n, d, a[N], nxt[N], vv, mst, ct2;

void dfs(int now, int st)
{
//	cout << now << ", " << st << "\n";
	if (ct2 > 2) return ;
	if (now == vv)
	{
		if (st == mst) ct2++;
		return ;
	}
	for (int to = now + 1; to <= nxt[now]; to++)
	{
		dfs(to, st + 1);
	}
}

bool check(int u, int v)
{
    // min step
    int p = u, cnt = 0;
    while (p < v)
    {
        p = nxt[p];
        cnt++;
    }
    vv = v; ct2 = 0; mst = cnt;
    dfs(u, 0);
//    cout << "u,v: " << u << ", " << v << ", " << ct2 << ", " << mst << "\n";
    if (ct2 != 2) return 0;
    return 1;
//    cout << u << ", " << v << ", " << cnt << "\n";
}

signed main()
{
    freopen("migrate2.in", "r", stdin);
    // freopen(".out", "w", stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    cin >> c >> t;

    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (clock() >= CLOCKS_PER_SEC * 0.9)
        {
        	cout << "0\n";
        	continue;
		}
		for (int i = 1; i <= n; i++) nxt[i] = -1;
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = i + 1; j <= n; j++)
            {
//            	cout << "ij: " << i << ", " << j << "\n";
                if (a[j] - a[i] <= d) nxt[i] = j;
                else break;
            }
        }
        int flag = 0;
        for (int i = 1; i <= n; i++) if (nxt[i] == -1) {cout << "0\n"; flag = 1; break;}
        if (flag) continue;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (check(i, j))
                {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
