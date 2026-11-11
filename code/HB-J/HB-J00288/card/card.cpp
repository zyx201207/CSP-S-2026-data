#include <bits/stdc++.h>
using namespace std;
vector<int> a, t;
int cnt[300005];
bool tx[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < n; i++)
    {
        t.clear();
        memset(tx, 0, sizeof tx);
        for(int j = i; j < n; j++)
        {
            int p = a[j];
            t.erase(find(t.begin(), t.end(), p), t.end());
            t.push_back(p);
        }
        for(int j : t)
            tx[j] = 1;
        for(int j = 1; j <= m; j++)
        {
            cnt[j] += tx[j];
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << cnt[i] << ' ';
    }
    return 0;
}