#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int a[N], n, d;
int mn[N], cnt[N];
void dfs(int i, int tmp)
{
    if (tmp < mn[i])
    {
        mn[i] = tmp;
        cnt[i] = 1;
    }
    else if (tmp == mn[i])
        cnt[i] ++;
    else return ;
    for (int j = i + 1; j <= n; j ++)
    {
        if (a[j] - a[i] > d) break;
        dfs(j, tmp + 1);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int id, T;
    cin >> id >> T;
    while (T --)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        int tot = 0;
        for (int i = 1; i <= n; i ++)
        {
            memset(mn, 0x3f, sizeof(mn));
            memset(cnt, 0, sizeof(cnt));
            dfs(i, 0);
            for (int j = i + 1; j <= n; j ++)
                if (cnt[j] == 2) tot ++;
        }
        cout << tot << "\n";
    }

    return 0;
}