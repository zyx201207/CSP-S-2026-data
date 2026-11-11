#include<bits/stdc++.h>
using namespace std;

int main() {

   freopen("string.in" ,"r", stdin);
   freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[n];
    char c[n];

    long long cnt = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> c[i];
        cnt += a[i];
    }

    int i = 0, j = n - 1;
    long long ans = 0;
    while(1) {

        if(j - i == 1) {
            if(c[i] != c[j]) {
                ans += min(a[i], a[j]);
            }
            break;
        }

        if(a[i] == a[j]) {
            if(c[i] != c[j]) {
                ans += a[i];
            }
            ++i;
            --j;
        } else {
            if(a[i] > a[j]) {
                if(c[i] != c[j]) {
                    ans += a[j];
                }
                a[i] -= a[j];
                --j;
            } else {
                if(c[i] != c[j]) {
                    ans += a[i];
                }
                a[j] -= a[i];
                ++i;
            }

        }

    }

    cout << ans << '\n';

    return 0;
}
