#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 +  10;
struct node{
    int a;
    char c;
}st[N], s[N];
int n, ans = 0;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    long long L = 0;
    for (int i = 1; i <= n; i++) {
        cin >> st[i].a >> st[i].c;
        L += st[i].a;
    }
    int cntn = 0;
    for (int i = 1; i <= n; i++) {
        char xc = st[i].c;
        long long cnt = 0;
        while (st[i].c == xc) {
            cnt += st[i].a;
            i++;
        }
        i--;
        s[i].a = cnt, s[i].c = xc, cntn++;
    }
    bool flag = true;
    for (int i = 1; i <= ceil(float(cntn / 2)); i++) {
        if (s[i].a != s[cntn + 1 - i].a){
            flag = false;
            break;
        }
        else if (s[i].c != s[cntn + 1 - i].c) {
            flag = false;
            break;
        }
    }
    if (flag == true) {
        cout << 0 << endl;
        return 0;
    }
    string ss;
    int cnta = 0;
    for (int i = 1; i <= cntn; i++) {
        char cc = s[i].c;
        for (int j = 1; j <= s[i].a; j++) {
            ss += cc;
        }
    }
    long long mid = ceil(float(L / 2));
    for (int i = 1; i <= ceil(float(L / 2)); i++) {
        if (ss[i] != ss[L + 1 - i]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

