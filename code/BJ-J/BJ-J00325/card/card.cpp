#include<bits/stdc++.h>
using namespace std;

long long a[100010] , n , m , mx , vis[5000];

int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    long long maxn = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn , a[i]);
    }
    if (maxn <= 4)
    {
        int cnt[10] = {};
        for (int i = 1; i <= n; i++) cnt[a[i]]++;
        if (cnt[4] >= m) cout << 4 << endl;
        else if (cnt[3] >= m) cout << 3 << endl;
        else if (cnt[2] >= m || cnt[2] + cnt[3] >= m)cout << 2 << endl;
        else if (cnt[1] >= m || cnt[1] + cnt[3] >= m)cout << 1 << endl;
        else cout << 0 << endl;
    }
    else if (m == 1) cout << maxn << endl;
    else if (n <= 20)
    {
        sort(a + 1 , a + n + 1);
        do
        {
            long long cnt = a[1];
            for (int i = 2; i <= m; i++) cnt = cnt & a[i];
            mx = max(mx , cnt);
        } while(next_permutation(a + 1 , a + n + 1));
        cout << mx << endl;
    }
    else if (m = n - 1)
    {
        for (int i = 1; i <= n; i++)
        {
            long long cnt;
            if (i != 1) cnt = a[1];
            else cnt = a[2];
            for (int j = 1; j <= n; j++)
            {
                if (j == i) continue;
                cnt = cnt & a[j];
            }
            mx = max(mx , cnt);
        }
        cout << mx << endl;
    }
    return 0;
}
