#include <bits/stdc++.h>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

const int MAXN = 2e6 + 10;

int n; ll d, a[MAXN];
int nxt[MAXN], pre[MAXN];
int cntn[MAXN], cntp[MAXN], sn[MAXN], sp[MAXN];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int cid, T; cin >> cid >> T;
    while (T--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1, j = i; i <= n; i++)
        {
            while (j < n && a[j + 1] <= a[i] + d) j++;
            nxt[i] = j;
        }
        for (int i = n, j = n; i >= 1; i--)
        {
            while (j > 1 && a[j - 1] >= a[i] - d) j--;
            pre[i] = j;
        }
        for (int i = 1; i <= n; i++) cntn[i] = cntp[i] = sn[i] = sp[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (nxt[i] > i) cntn[nxt[i]]++;
            if (pre[i] < i) cntp[pre[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            sn[i] = cntn[i];
            if (pre[i] < i && nxt[pre[i]] == i) sn[i] += sn[pre[i]];
        }
        for (int i = n; i >= 1; i--)
        {
            sp[i] = cntp[i];
            if (nxt[i] > i && pre[nxt[i]] == i) sp[i] += sp[nxt[i]];
        }
        ll ans = 0;
        for (int i = 1; i < n; i++) if (nxt[i] > i + 1 && pre[i + 1] < i)
        {
            ans += (ll)cntn[i + 1] * cntp[i];
            if (pre[i] < i && nxt[pre[i]] == i + 1) ans += (ll)sn[pre[i]] * cntp[i];
            if (nxt[i + 1] > i + 1 && pre[nxt[i + 1]] == i) ans += (ll)sp[nxt[i + 1]] * cntn[i + 1];
            if (pre[i] < i && nxt[pre[i]] == i + 1 && nxt[i + 1] > i + 1 && pre[nxt[i + 1]] == i) ans += (ll)sn[pre[i]] * sp[nxt[i + 1]];
        }
        cout << ans << '\n';
    }
    return 0;
}