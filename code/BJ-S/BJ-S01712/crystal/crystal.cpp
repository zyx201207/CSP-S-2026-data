#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, m, sum = 0;
int cnt[N];
int cr[N];
int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        cr[i] = z;
        if (i == 0) {
            cnt[i] = cr[i];
        }
        else cnt[i] = cnt[i-1] + cr[i];
    }
    for (int i = 0; i < n-1; i++) {
        int f = cnt[i+1] - cnt[i];
        int tmp = 1;
        int j = i + 1;
        while (f <= m && j < n) {
            f += (cr[j+1] + cr[j] * cr[j-i]);
            j++;
            tmp++;
        }
        sum = max(j-1, tmp);
    }
    cout << sum << '\n';
    return 0 ;
}
