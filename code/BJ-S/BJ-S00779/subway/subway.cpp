#include <bits/stdc++.h>
using namespace std;

int k[505], a[505][500005], t[505][500005];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c = 0, n = 0, m = 0, d = 0, q = 0;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(n + 5);
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    while(q--)
    {
        int x = 0, y = 0;
        cin >> x >> y;
        int sum = 0;
        sum += w[x] + w[y];
        cout << w[x] << " " << w[y] << " ";
        int min1 = 1e9, min2 = 1e9, b = 0, c = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k[i]; j++)
            {
                for(int z = 1; z <= k[i]; z++)
                {
                    if(a[j][z] == x)
                    {
                        if(t[j][z] < min1)
                        {
                            min1 = t[j][z];
                            b = i;
                        }
                    }
                    if(a[j][z] == y)
                    {
                        if(t[j][z] < min2)
                        {
                            min2 = t[j][z];
                            c = i;
                        }
                    }
                }
            }
        }
        if(b != c)
        {
            bool flag = false;
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= k[i]; j++)
                {
                    for(int z = 1; z <= k[i]; z++)
                    {
                        if(a[i][j] == a[j][z])
                        {
                            sum += t[i][j] + t[j][z];
                            cout << t[i][j] << " " << t[j][z] << " ";
                            flag = true;
                            break;
                        }
                    }
                    if(flag == true)
                    {
                        break;
                    }
                }
                if(flag == true)
                {
                    break;
                }
            }
        }
        sum += t[b][x] + t[c][y];
        cout << t[b][x] << " " << t[c][y] << " ";
        cout << sum << "\n";
    }
    return 0;
}
