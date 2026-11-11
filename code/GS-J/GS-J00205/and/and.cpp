#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, c ,a[N];

int main()
{
    freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);
    c = a[n];
    for(int i = n - 1; i >= n - m + 1; i--)
    {
         c = c & a[i];
    }
    cout << c;
    return 0;
}
