#include <bits/stdc++.h>
using namespace std;

long long f2(long long x) {
    long long a = 0;
    while(x > 0) {
        if(x % 2) {
            a++;
            x = (x - 1) / 2;
        }
        else {
            x /= 2;
        }
    }

    return a;
}

bool f(int x, int y) {
    return f2(x) > f2(y);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    long long n, m;
    cin >> n >> m;

    long long arr[n + 1];
    for(int i = 1 ; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1, f);

    long long ans = arr[1];
    for(int i = 2; i <= m; i++) {
        ans &= arr[i];
    }

    cout << ans << endl;

    return 0;
}
