#include <bits/stdc++.h>
using namespace std;
int n, num[200005], sum, ans;
char c;
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %c", &num[i], &c);
        sum += num[i];
        for (int j = 1; j <= num[i]; j++) {
            s = s + c;
        }
    }
    for (int i = 0; i < sum / 2; i++) {
        if (s[i] != s[sum - i - 1]) {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

