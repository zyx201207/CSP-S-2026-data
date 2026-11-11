#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << '\n';

using namespace std;

void solve(int n, int m)
{
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans(m + 1);
    for (int i = 0; i < n; i++) {
        int idx = -1;
        vector<int> table(n);
        for (int j = i; j < n; j++) {
            bool flg = false;
            set<int> st;
            for (int k = 0; k <= idx; k++) {
                if (table[k] == a[j]) {
                    idx = k;
                    flg = true;
                    break;
                }
            }
            if (flg)
                continue;
            table[++idx] = a[j];
        }
        for (int i = 0; i <= idx; i++) {
            ans[table[i]]++;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    // if (n <= 500)
    solve(n, m);
    // else
    // solve2(n, m);
    return 0;
}