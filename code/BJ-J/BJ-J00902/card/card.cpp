#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int b[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a[500005];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            bool flag = false;
            int ind;
            for (int k = 0; k < v.size(); k++)
            {
                if (v[k] == a[j])
                {
                    flag = true;
                    ind = k;
                    break;
                }
            }
            if (!flag)
                v.push_back(a[j]);
            else
            {
                for (int k = v.size() - 1; k > ind; k--)
                    v.pop_back();
            }
        }
        for (int j = 0; j < v.size(); j++)
            b[v[j]]++;
        v.clear();
    }
    for (int i = 1; i <= m; i++)
        cout << b[i] << " ";
    return 0;
}
