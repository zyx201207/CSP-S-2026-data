#include <bits/stdc++.h>
using namespace std;
long long n, res = 0, mid = 0, a[200005], sum[200005];
long long sm = 0;
long long equalcnt = 0;
long long realid;
long long idcnt = 0;
string ss = "";
char s[200005];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> s[i];
        for (int j = 1; j <= a[i]; j++) {
            ss += s[i];
        }
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 0; i <= sum[n] / 2; i++) {
        if (ss[i] != ss[ss.size() - i - 1]) {
            res++;
        }
    }
    cout << res;

    return 0;
}
