#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
unordered_map<int, int> mp;
vector<vector<int>> v;
int w[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        if (mp.count(a[i]))
            v.push_back(v[n - mp[i]]);
        else
        {
            if (v.empty())
            {
                vector<int> ss;
                ss.clear();
                ss.push_back(a[i]);
                v.push_back(ss);
            }
            else
            {
                vector<int> cc = v.back();
                cc.push_back(a[i]);
                v.push_back(cc);
            }
            mp[a[i]] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            w[v[i][j]]++;
    }
    for (int i = 1; i <= m; i++)
        cout << w[i] << ' ';
    return 0;
}