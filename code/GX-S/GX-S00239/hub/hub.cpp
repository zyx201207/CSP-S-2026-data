#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("hub.in", "r", stdin);
    //freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a[100001];
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }
    return 0;
}

