#include <bits/stdc++.h>
using namespace std;
int n, m,a[100000];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int sum = a[1];
    for (int = 2; i <= m; i++){
        sum = sum & a[i];
    }
	cout << sum;
    return 0;
}
