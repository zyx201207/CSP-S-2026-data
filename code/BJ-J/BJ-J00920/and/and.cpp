#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
vector<int> now, pre;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], pre.push_back(a[i]);
    for (int i = 30; i >= 0; i--)
    {
        now.clear();
        for (int j : pre)
        {
            if (j & (1 << i)) now.push_back(j);
        }
        if (now.size() >= m) pre = now, ans += (1 << i);
        // if (now.size() == m) break;
    }
    // for (int i : pre) cout << i << ' ';
    cout << ans;
    return 0;
}

/*
4 2
3 15 12 12
*/

// 10:22