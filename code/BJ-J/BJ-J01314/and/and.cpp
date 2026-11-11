#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            maxn = max(maxn,a[i]);
        }
        cout << maxn << endl;
    }
    else if(m == 2)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                int x = a[i] & a[j];
                maxn = max(maxn,x);
            }
        }
        cout << maxn << endl;
    }
    else if(m == n)
    {
        int ans = a[1];
        for(int i = 2;i <= n;i++)
        {
            ans &= a[i];
        }
        cout << ans << endl;
    }
    else if(m == 3)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    int x = a[i] & a[j] & a[k];
                    maxn = max(maxn,x);
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 4)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;k <= n;l++)
                    {
                        int x = a[i] & a[j] & a[k] & a[l];
                        maxn = max(maxn,x);
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 5)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            int x = a[i] & a[j] & a[k] & a[l] & a[o];
                            maxn = max(maxn,x);
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 6)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p];
                                maxn = max(maxn,x);
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 7)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q];
                                    maxn = max(maxn,x);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 8)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r];
                                        maxn = max(maxn,x);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 9)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s];
                                            maxn = max(maxn,x);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 10)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t];
                                                maxn = max(maxn,x);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 11)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u];
                                                    maxn = max(maxn,x);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 12)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    for(int v = u + 1;v <= n;v++)
                                                    {
                                                        int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u] & a[v];
                                                        maxn = max(maxn,x);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 13)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    for(int v = u + 1;v <= n;v++)
                                                    {
                                                        for(int w = v + 1;w <= n;w++)
                                                        {
                                                            int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u] & a[v] & a[w];
                                                            maxn = max(maxn,x);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 14)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    for(int v = u + 1;v <= n;v++)
                                                    {
                                                        for(int w = v + 1;w <= n;w++)
                                                        {
                                                            for(int y = w + 1;y <= n;y++)
                                                            {
                                                                int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u] & a[v] & a[w] & a[y];
                                                                maxn = max(maxn,x);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 15)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    for(int v = u + 1;v <= n;v++)
                                                    {
                                                        for(int w = v + 1;w <= n;w++)
                                                        {
                                                            for(int y = w + 1;y <= n;y++)
                                                            {
                                                                for(int z = y + 1;z <= n;z++)
                                                                {
                                                                    int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u] & a[v] & a[w] & a[y] & a[z];
                                                                    maxn = max(maxn,x);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 16)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    for(int v = u + 1;v <= n;v++)
                                                    {
                                                        for(int w = v + 1;w <= n;w++)
                                                        {
                                                            for(int y = w + 1;y <= n;y++)
                                                            {
                                                                for(int z = y + 1;z <= n;z++)
                                                                {
                                                                    for(int aa = z + 1;aa <= n;aa++)
                                                                    {
                                                                        int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u] & a[v] & a[w] & a[y] & a[z] & a[aa];
                                                                        maxn = max(maxn,x);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 17)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    for(int v = u + 1;v <= n;v++)
                                                    {
                                                        for(int w = v + 1;w <= n;w++)
                                                        {
                                                            for(int y = w + 1;y <= n;y++)
                                                            {
                                                                for(int z = y + 1;z <= n;z++)
                                                                {
                                                                    for(int aa = z + 1;aa <= n;aa++)
                                                                    {
                                                                        for(int ab = aa + 1;ab <= n;ab++)
                                                                        {
                                                                            int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u] & a[v] & a[w] & a[y] & a[z] & a[aa] & a[ab];
                                                                            maxn = max(maxn,x);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 18)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    for(int v = u + 1;v <= n;v++)
                                                    {
                                                        for(int w = v + 1;w <= n;w++)
                                                        {
                                                            for(int y = w + 1;y <= n;y++)
                                                            {
                                                                for(int z = y + 1;z <= n;z++)
                                                                {
                                                                    for(int aa = z + 1;aa <= n;aa++)
                                                                    {
                                                                        for(int ab = aa + 1;ab <= n;ab++)
                                                                        {
                                                                            for(int ac = ab + 1;ac <= n;ac++)
                                                                            {
                                                                                int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u] & a[v] & a[w] & a[y] & a[z] & a[aa] & a[ab] & a[ac];
                                                                                maxn = max(maxn,x);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    else if(m == 19)
    {
        int maxn = -1e9;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                for(int k = j + 1;k <= n;k++)
                {
                    for(int l = k + 1;l <= n;l++)
                    {
                        for(int o = l + 1;o <= n;o++)
                        {
                            for(int p = o + 1;p <= n;p++)
                            {
                                for(int q = p + 1;q <= n;q++)
                                {
                                    for(int r = q + 1;r <= n;r++)
                                    {
                                        for(int s = r + 1;s <= n;s++)
                                        {
                                            for(int t = s + 1;t <= n;t++)
                                            {
                                                for(int u = t + 1;u <= n;u++)
                                                {
                                                    for(int v = u + 1;v <= n;v++)
                                                    {
                                                        for(int w = v + 1;w <= n;w++)
                                                        {
                                                            for(int y = w + 1;y <= n;y++)
                                                            {
                                                                for(int z = y + 1;z <= n;z++)
                                                                {
                                                                    for(int aa = z + 1;aa <= n;aa++)
                                                                    {
                                                                        for(int ab = aa + 1;ab <= n;ab++)
                                                                        {
                                                                            for(int ac = ab + 1;ac <= n;ac++)
                                                                            {
                                                                                for(int ad = ac + 1;ad <= n;ad++)
                                                                                {
                                                                                    int x = a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t] & a[u] & a[v] & a[w] & a[y] & a[z] & a[aa] & a[ab] & a[ac] & a[ad];
                                                                                    maxn = max(maxn,x);
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << maxn << endl;
    }
    return 0;
}
