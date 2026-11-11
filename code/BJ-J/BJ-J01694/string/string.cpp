#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n, a[N], cnt;
char c[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    int i = 1, j = n;
    while(i < j) {
        if(c[i] != c[j]) {
            if(a[i] > a[j]) {
                cnt += a[j];
                a[i] -= a[j];
                j--;
            } else {
                cnt += a[i];
                a[j] -= a[i];
                i++;
            }
        } else {
            if(a[i] > a[j]) {
                a[i] -= a[j];
                j--;
            } else a[j] -= a[i], i++;
        }
    }
    cout << cnt << endl;
    return 0;
}