#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
int n;
long long a[MAX_N];
char c[MAX_N];
string s;

void addition(long long a, char c) {
    string temp = "", ans = "";
    temp += c;
    while (a > 0) {
        if (a & 1 == 1) ans += temp;
        temp += temp;
        a >>= 1;
    }
    s += ans;
    return ;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> c[i];
        addition(a[i], c[i]);
    }

    long long ans = 0;
    long long index = 0;
    int part = 1;
    while (index < s.size()/2) {
        if (s[index] != s[s.size()-1-index]) {
            ans++;
        }
        index++;
    }
    cout << ans << endl;

    return 0;
}
