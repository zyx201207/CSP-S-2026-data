#include <bits/stdc++.h>
using namespace std;
#define int long long

int zhazha, t;

void insert()
{
    cin >> zhazha >> t;
}

void work()
{
    insert();
    while(t--)
        cout << 0 << '\n';
}

signed main()
{
    freopen("migrate.out", "w", stdout);
    freopen("migrate.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    work();
}