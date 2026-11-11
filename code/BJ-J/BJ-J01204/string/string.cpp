#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n, a[N], c[N];
    int ar[N], cr[N];

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        char ch;
        cin >> ch;
        c[i] = ch - 'a';
        ar[n - i + 1] = a[i];
        cr[n - i + 1] = c[i];
    }

    long long ans = 0;

    int i = 1, j = 1;
    int di = 0, dj = 0;
    int len;
    while (i <= n && j <= n) {
        if(di + a[i] < dj + ar[j]) {
            len = di + a[i];
            if(c[i] != cr[j]) ans += len;
            dj -= di + a[i];
            di = 0;
            i++;
        }
        else if(di + a[i] > dj + ar[j]) {
            len = dj + ar[j];
            if(c[i] != cr[j]) ans += len;
            di -= dj + ar[j];
            dj = 0;
            j++;
        }
        else {
            len = di + a[i];
            if(c[i] != cr[j]) ans += len;
            di = 0;
            dj = 0;
            i++;
            j++;
        }
    }

    cout << ans / 2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
