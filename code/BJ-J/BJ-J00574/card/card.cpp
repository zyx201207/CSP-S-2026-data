#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], vis[500005];


int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m-1; i++)
    {
        cout << 0 << " ";
    }
    cout << n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

