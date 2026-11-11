#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[500005];
int f[500005];
int ff[500005];
int g[500005];
int c[500005];
int s[500005];
int ans[500005];

signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = n; i >= 1; i--)
        if(ff[a[i]] == 0) ff[a[i]] = i;
    for(int i = 1; i <= n; i++)
        f[i] = ff[a[i]];
    int last = n + 1;
    for(int i = n; i >= 1; i--)
        if(f[i] != i) g[i] = i, last = i;
        else g[i] = last;
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        while(j <= n)
        {
            c[g[j]]--, c[j]++;
            j = g[j];
            if(j <= n) j = f[j], c[j+1]--, c[j]++;
            j++;
        }
    }
    for(int i = 1; i <= n; i++)
        s[i] = s[i-1] + c[i], ans[a[i]] += s[i];
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';

    return 0;
}