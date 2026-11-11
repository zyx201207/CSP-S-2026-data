#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200010], s;
char c[200010];

int main() {

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i] >> c[i];
    int L=0, R = n-1;
    while(L < R) {
        if(a[L] < a[R]) {
            L++, a[R] -= a[L];
            if(c[L] != c[R]) s += a[L];
        }
        else if(a[L] > a[R]) {
            R--, a[L] -= a[R];
            if(c[L] != c[R]) s += a[R];
        }
        else {
            L++, R--;
            if(c[L] != c[R]) s += a[L];
        }
    }

    cout << s;

    return 0;
}
