#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6+5;
int c, t, n, k;
vector<int> e[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1,u,v; i < n; i++)
        {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cout << k-1 << '\n';
    }
    return 0;
}
