#include<bits/stdc++.h>
using namespace std;

int n, m, a[5010], t[5010], id[5010], ans[5010];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        memset(t, 0, sizeof(t));
        memset(id, 0, sizeof(t));
        int l = 1e9, r = -1e9;
        for(int j = i; j <= n; j++)
        {
            if((l == 0 && r == 0 && id[a[j]]) || (id[a[j]] && !(l <= id[a[j]] && id[a[j]] <= r)))
            {
                t[id[a[j]]] -= 1;
                t[j] += 1;
                l = id[a[j]];
                r = j - 1;
            }
            id[a[j]] = j;
            t[j] += 1;
            t[j + 1] -= 1;
        }
        int sum = 0;
        for(int j = i; j <= n; j++)
        {
            sum += t[j];
            if(sum > 0) ans[a[j]]++;
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
    return 0;
}