#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
const int maxn = 2e5 + 5;
int n, al, ar, a[maxn];
char c[maxn];
ull midl, midr, pl = 1ll, pr, sum[maxn];
long long ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        pr += a[i];
    }
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (ull) a[i];
    if(sum[n] % 2 == 0)
    {
        midl = (ull) sum[n] / 2;
        midr = midl + 1ll;
    }
    else
    {
        midl = (ull) sum[n] / 2;
        midr = midl + 2ll;
    }
    al = 1, ar = n;
    while(pl <= midl && pr >= midr)
    {
        ull cl = min(midl - pl + 1, sum[al] - pl + 1), cr = min(pr - midr + 1, pr - sum[ar - 1]);
        if(c[al] == c[ar])
        {
            if(cl < cr)
            {
                pl += cl; pr -= cl; al++;
            }
            else if(cl > cr)
            {
                pl += cr; pr -= cr; ar--;
            }
            else
            {
                pl += cl; pr -= cl; al++; ar--;
            }
        }
        else
        {
            if(cl < cr)
            {
                pl += cl; pr -= cl; al++;
                ans += cl;
            }
            else if(cl > cr)
            {
                pl += cr; pr -= cr; ar--;
                ans += cr;
            }
            else
            {
                pl += cl; pr -= cl; al++; ar--;
                ans += cl;
            }
        }
    }
    cout << ans;
	return 0;
}
