#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define ll long long
const int N = 2e6 + 5;
int cid, T, n, u[N], v[N]; ll d, x[N], f[N], g[N], ans;
int main()
{
    FILE("migrate");
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> cid >> T;
    while (T--)
    {
        for (int i = 1; i <= n; i++) f[i] = g[i] = x[i] = 0;
        cin >> n >> d; x[0] = -4e18; x[n+1] = 4e18; ans = 0;
        for (int i = 1; i <= n; i++) cin >> x[i]; 
        for (int i = 1, j = 0; i <= n + 1; i++)
        {
            while (x[j] < x[i] - d) j++;
            u[i] = j;
        }
        for (int i = n, j = n + 1; i >= 0; i--)
        {
            while (j && x[j-1] > x[i] + d) j--;
            v[i] = j;
        }
        for (int i = 1; i <= n; i++)
        {
            int l = u[i], r = u[i+1] - 1;
            l = max(1, l); r = min(i - 1, r);
            if (l <= r) f[i] = f[l] + r - l + 1; 
            else f[i] = 1;
        }
        for (int i = n; i >= 1; i--)
        {
            int r = v[i] - 1, l = v[i-1];
            l = max(i + 1, l); r = min(n, r);
            if (l <= r) g[i] = g[r] + r - l + 1; 
            else g[i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            int Ll = u[i+1], Lr = u[i+2] - 1;
            Ll = max(1, Ll); Lr = min(i - 1, Lr);
            int Rr = v[i] - 1, Rl = v[i-1];
            Rl = max(i + 2, Rl); Rr = min(n, Rr);
            if (Ll > Lr || Rl > Rr) continue;
            ll v1 = 1, v2 = 1;
            if (x[i] - x[Ll-1] > d) v1 = f[Ll];
            if (x[Rr+1] - x[i+1] > d) v2 = g[Rr];
            ans += (Lr - Ll) * (Rr - Rl);
            ans += v1 * (Rr - Rl);
            ans += (Lr - Ll) * v2;
            ans += v1 * v2;
        }
        cout << ans << "\n";
    }
    return 0;
}