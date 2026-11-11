#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 1;
int n;
ll L, a[N], len, ans;
char c[N];
string s;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %c", &a[i], &c[i]);
        L += a[i];
    }
    //cout << L << '\n';
    if (L > 10000000) {
        for (int i = 1, j = n; i < j; ) {
            ll need = 0; // 当前要修改的次数
            if (a[i] != a[j] && c[i] == c[j]) { // 如果已经构成回文串
                int ti = i, tj = j; bool f = 0;
                while (ti < tj) {
                    if (c[ti] != c[tj]) {
                        f = 1;
                        break;
                    }
                    ti++; tj--;
                }
                if (!f) {
                    printf("0");
                    return 0;
                }
            }
            if (a[i] == a[j]) { // 相等情况
                if (c[i] == c[j]) {
                    i++; j--;
                    continue;
                }
                ans += a[i];
                c[j] = c[i];
                i++; j--;
            } else if (a[i] < a[j]) { // l < r
                if (c[i] == c[j]) need = a[j] - a[i]; // 要补的数量
                else need = a[j];
                ans += need;
                a[i] = a[j]; a[i + 1] -= a[j] - a[i];
                c[i] = c[j];
                i++; j--;
            } else { // l > r
                if (c[i] == c[j]) need = a[i] - a[j]; // 多的
                else need = a[i];
                ans += need;
                a[j] = a[i]; a[j - 1] -= a[i] - a[j];
                c[i] = c[j];
                i++; j--;
            }
        }
        printf("%lld", ans);
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= a[i]; j++) {
                s += c[i];
            }
        }
        //cout << s << '\n';
        ll len = s.size();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - i - 1]) {
                ans++;
            }
        }
        printf("%lld", ans);
    }
    return 0;
}

// Trick or Treat!
