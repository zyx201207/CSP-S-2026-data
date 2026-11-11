#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int num[MAXN];
char ch[MAXN];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> num[i] >> ch[i];
    }
    long long ans = 0;
    int hd = 0, tl = N + 1;
    long long bal = 0;  // pre_len - suf_len
    while (hd + 1 < tl) {
        if (bal >= 0) {  // suf.append
            tl--;
            if (hd >= 1) {
                if (ch[hd] != ch[tl]) {
                    ans += min(bal, (long long)num[tl]);
                }
            }
            bal -= num[tl];
        } else {  // pre.append
            hd++;
            if (tl <= N) {
                if (ch[tl] != ch[hd]) {
                    ans += min(-bal, (long long)num[hd]);
                }
            }
            bal += num[hd];
        }
    }
    cout << ans;
    return 0;
}