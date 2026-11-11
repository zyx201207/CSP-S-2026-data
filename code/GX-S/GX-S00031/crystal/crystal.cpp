#include <bits/stdc++.h>
using namespace std;

long long h[5000005];

struct s {
    long long a, c;
} arr[5000005];

bool f(s a, s b) {
    return a.a < b.a;
}

bool f2(s a, s b) {
    return a.c < b.c;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    long long ans = 1;
    long long n;
    unsigned long long m;
    cin >> n >> m;

    long long c;
    bool x = true;
    for(long long i = 1; i <= n; i++) {
        cin >> arr[i].a;

        if(n >= 2) {
            if((arr[i].a - arr[i - 1].a == arr[i - 1].a - arr[i - 2].a) && x && i > 2) {
                c = arr[i].a - arr[i - 1].a;
                x = true;
                //cout << "bbb" << endl;
            }
            else if(!(arr[i].a - arr[i - 1].a == arr[i - 1].a - arr[i - 2].a) && i > 2) {
                x = false;
                //cout << "aaa" << endl;
            }
        }
        else {
            cout << ans << endl;
            return 0;
        }
    }

    if(x) {
        long long xx = m / c;
        //cout << xx << endl;
        long long i = 1;
        while(xx >= i) {
            xx -= i;
            i++;
            ans++;
        }

        cout << ans << endl;
        //cout << "dengcha";
        return 0;
    }

    sort(arr + 1, arr + n + 1, f);


    for(long long i = 2; i <= n; i++) {
        arr[i].c = arr[i].a - arr[i - 1].a;
    }

    sort(arr + 2, arr + n + 1, f2);

    for(long long i = 2; i <= n; i++) {
        h[i] = h[i - 1] += arr[i].c;
    }

    if(m >= h[n]) {
        cout << n << endl;
        return 0;
    }

    unsigned long long maxn = 1;
    for(long long i = 1; i <= n; i++) {
        for(long long j = 1; j <= i; j++) {
            if(h[i] - h[j] <= m) {
                long long cnt = i + j - 1;
                if(maxn < cnt) {
                    maxn = cnt;
                }
            }
        }
    }

    cout << maxn << endl;

    return 0;
}
