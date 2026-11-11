#include <bits/stdc++.h> //100 pts
// dzd 以后别在 J组 T2 出这种大模拟了好唐啊
// ???????? 收题系统居然是有AC自动机敏感词过滤逆天 
using namespace std;
#define int long long
const int N = 2e5 + 2;
struct node {
    int cnt;
    char c;
} a[N], l[N], r[N];
int n, sum, ltot, rtot, mid, ans;
void init () {
    mid = sum / 2;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i].cnt < mid) {
            sum += a[i].cnt;
            l[++ltot] = a[i];
        }
        else {
            int tmp = mid - sum;
            sum += tmp;
            l[++ltot] = {tmp, a[i].c};
            break;
        }
    }
    sum = 0;
    for (int i = n; i >= 1; i--) {
        if (sum + a[i].cnt < mid) {
            sum += a[i].cnt;
            r[++rtot] = a[i];
        }
        else {
            int tmp = mid - sum;
            sum += tmp;
            r[++rtot] = {tmp, a[i].c};
            break;
        }
    }
    sum = 0;
    return;
}
void sol () {
    int i = 1;
    int j = 1;
    int lpos = 1;
    int rpos = 1;
    while (i <= ltot && j <= rtot) {
        int lcnt = l[i].cnt - lpos + 1;
        int rcnt = r[j].cnt - rpos + 1;
        int lc = l[i].c;
        int rc = r[j].c;
        if (lc == rc) {
            if (lcnt > rcnt) {
                j++;
                rpos = 1;
                lpos += rcnt;
                continue;
            }
            else {
                i++;
                lpos = 1;
                rpos += lcnt;
                continue;
            }
        }
        else {
            if (lcnt > rcnt) {
                j++;
                rpos = 1;
                ans += rcnt;
                lpos += rcnt;
                continue;
            }
            else {
                i++;
                lpos = 1;
                ans += lcnt;
                rpos += lcnt;
                continue;
            }
        }
    }
    return;
}
signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1ll; i <= n; i++) {
        cin >> a[i].cnt >> a[i].c;
        sum += a[i].cnt;
    }
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    init();
    sol();
    cout << ans << '\n';
    return 0;
}
//freopen("string.in", "w", stdin);
//freopen("string.in", "r", stdout);
/*
CNUHS is the best high school in the world!
*/