#include <bits/stdc++.h>
using namespace std;
#define ll long long

// int f10t2(int f10) {
//         int t2;
//     while(true) {
//         t2*=10; t2+=(f10%2); f10/=2;
//         if (f10 == 0) break;
//     } return t2;
// }

int main() {
    // freopen("and.in", "r", stdin);
    // freopen("and.out", "w", stdout);

    int n, m, a[666666], maxn=0; cin >> n >> m; for (int i = 0; i < n; i++) {
        // int tmp; cin >> tmp;
        // a[i] = f10t2(tmp);
        cin >> a[i];
        for (int j = i; j >= 0; j--) {
            if ((a[i] & a[j]) > maxn) maxn = (a[i] & a[j]);
        }
    } cout << maxn;
}
