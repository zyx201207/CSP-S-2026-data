#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
using namespace std;
long long n, ans, a[maxn];
char s[maxn];
string sum;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i]; j++)
            sum += s[i];
    }
 //   cout << sum;
    for (long long i = 0; i < sum.size() / 2LL; i++) {
        if (sum[i] != sum[sum.size() - i - 1]) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
