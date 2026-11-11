#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], cnt[N];
bool f[N];
vector<int> v;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        v.clear();
        memset(f, false, sizeof f);
        for (int j = i; j <= n; j++)
        {
            if (!f[a[j]])
            {
                f[a[j]] = true;
                v.push_back(a[j]);
            }
            else
            {
                while (!v.empty() && v.back() != a[j])
                {
                    f[v.back()] = false;
                    v.pop_back();
                }
                if (!v.empty())
                {
                     f[v.back()] = false;
                     v.pop_back();
                }

                v.push_back(a[j]);
                f[a[j]] = true;
            }
        }
        for (int cur: v)
        {
            cnt[cur]++;
            //cout << cur << ' ';
        }
       // cout << '\n';
    }
    for (int i = 1; i <= m; i++)
    {
        cout << cnt[i] << ' ';
    }
    return 0;
}
