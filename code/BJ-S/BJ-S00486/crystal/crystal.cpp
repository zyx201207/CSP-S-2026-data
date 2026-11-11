

#include <bits/stdc++.h>

using namespace std;

long long n,m;
long long a[500009], f[500009], sum[500009], sum2[500009];
long long ans = 1;

bool Check(int s, int mid) {
    long long solo = a[s + mid - 1], res = 0;

    res = sum[s + mid - 1] - sum[s] - (solo - a[s]) * (s - 1);

    if(res > m) {
        return false;
    }


    return true;
}

int main () {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for(int i = 2; i <= n; i++) {
        f[i] = a[i] - a[i - 1];
    }

    sum[1] = 0;
    for(long long i = 2; i <= n; i++) {
        sum[i] += sum[i - 1] + f[i] * (i - 1);
    }

    int l = 1, r = n;

    while(l <= r) {
        int mid = (l + r) >> 1;
        bool flag = false;

        for(int i = 1; i <= n - mid + 1; i++) {
            if(Check(i, mid)) {
                flag = true;
                break;
            }
        }

        if(flag) {
            ans = mid;
            l = mid + 1;
        }

        else{
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
