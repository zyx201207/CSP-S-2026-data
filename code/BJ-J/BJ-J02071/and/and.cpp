#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000000];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = a[0];
    if (n == m) {
        for (int i = 1; i < n; i++) {
            ans = ans & a[i];
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}