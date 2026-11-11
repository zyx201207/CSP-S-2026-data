#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, ans = 0;
int a[N];
bool f = true, d = true;

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] != i - 1) d == false;
            if (a[i] >= 4) f = false;
    }
    if (m == 2) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                ans = max(ans, a[i] & a[j]);
        cout << ans << endl;
        return 0;
    }
    else if (m == 1) {
        sort(a + 1, a + n + 1, cmp);
        cout << a[1] << endl;
        return 0;
    }
    else if (m == n) {
            ans = a[1];
        for (int i = 2; i <= n; i++)
            ans = ans & a[i];
        cout << ans << endl;
        return 0;
    }
    else if (f == true) {
        sort(a + 1, a + n + 1, cmp);
        ans = a[1];
        if (m == 1) cout << ans << endl;
        for (int i = 2; i <= m; i++)
            ans = ans & a[i];
        cout << ans;
        return 0;
    }
    else if (d == true) {
        sort(a + 1, a + n + 1, cmp);
        ans = a[1];
        for (int i = 2; i <= m; i++)
            ans = ans & a[i];
        cout << ans << endl;
        return 0;
    }
    else {
        sort(a + 1, a + n + 1, cmp);
        ans = a[1];
        for (int i = 2; i <= m; i++)
            ans = ans & a[i];
        cout << ans << endl;
        return 0;
    }
    return 0;
}
