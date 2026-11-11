#include <bits/stdc++.h>
#define pii pair < int, int >
#define F first
#define S second
using namespace std;

typedef long long ll;

const int N = 5e5;
const int M = 3e5;

int n, m;

int a[N + 5], lst[M + 5];

int val[N + 5];

int ans[M + 5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        lst[a[i]] = i;
        val[i] = 1;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        ans[a[i]] += val[i];
        val[lst[a[i]] + 1] += val[i];
    }
    for (int i = 1 ; i <= m ; i++)
    {
        cout << ans[i];
        if (i != m) cout << ' ';
    }
    cout << '\n';
    return 0;
}
