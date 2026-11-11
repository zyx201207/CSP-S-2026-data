#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, a[500001], s[300001] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        map<int, int> b;
        for (int j = i; j < n; j++)
        {
            if (b[a[j]])
            {
                int t = b[a[j]];
                vector<int> tt;
                for (pair<int, int> i : b)
                {
                    if (i.second >= t)
                    {
                        tt.push_back(i.first);
                    }
                }
                for (int i : tt)
                {
                    b.erase(i);
                }
            }
            b[a[j]] = j + 1;
        }
        for (pair<int, int> i : b)
        {
            s[i.first]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << s[i] << ' ';
    }
    return 0;
}

