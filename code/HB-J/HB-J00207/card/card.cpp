#include <bits/stdc++.h>
using namespace std;
int a[500005], b[300005];
map<int, int> mp;
int ji[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        memset(ji, 0, sizeof ji);
        for (int j = i; j <= n; j++)
        {
            if (!mp[a[j]])
            {
                mp[a[j]] = j;
                ji[j] = a[j];
            }
            else
            {
                for (int k = mp[a[j]]; k <= n; k++)
                {
                    mp[ji[k]] = 0;
                    ji[k] = 0;
                }
                mp[a[j]] = j;
                ji[j] = a[j];
            }
        }
        mp.clear();
        for (int j = i; j <= n; j++)
        {
            b[ji[j]]++;
        }
        for (int j = i; j <= n; j++) cout << ji[j] << " ";
        cout << endl;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
