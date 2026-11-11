#include <iostream>
using namespace std;
const int N = 2E5 + 5;
typedef long long ll;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s = " ";
    ll sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        for (int j = 1; j <= a; j++)
            s += c;
        sum += a;
    }
    for (int i = 1; i <= sum / 2; i++) {
        if (s[i] != s[sum - i + 1]) cnt++;
    }
    cout << cnt;
    return 0;
}
