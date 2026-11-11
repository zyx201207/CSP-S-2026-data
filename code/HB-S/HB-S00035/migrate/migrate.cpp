#include <bits/stdc++.h>
#define int long long
#define loop(i, a, b) for(int i = (a) ; i <= (b) ; i++)
#define rloop(i, a, b) for(omt i = (a) ; i >= (b) ; i--)
#define chkmax(x, y) ((x) = max((x), (y)))
#define chkmin(x, y) ((x) = min((x), (y)))
#define mid (((l) + (r)) / 2)
#define lowbit ((x) & (-(x)))
using namespace std;
const int N = 2e6 + 5;
int n, d, a[N], l[N], dp1[N], dp2[N];
namespace subtask1 {
    int calc(int s) {
        dp1[s] = 0, dp2[s] = 1;
        int cnt = 0;
        loop(i, s + 1, n) {
            if(l[i] <= s) dp1[i] = 1, dp2[i] = 1;
            else if(l[i] == i) return cnt;
            else {
                dp1[i] = dp1[l[i]] + 1, dp2[i] = 0;
                loop(j, l[i], min(i - 1, l[i] + 2)) {
                    if(dp1[j] != dp1[l[i]]) break;
                    dp2[i] += dp2[j];
                }
            }
            cnt += (dp2[i] == 2);
        }
        return cnt;
    }
    void solve() {
        cin >> n >> d;
        loop(i, 1, n) cin >> a[i];
        int lp = 1;
        loop(rp, 1, n) {
            while(a[rp] - a[lp] > d) lp++;
            l[rp] = lp;
        }
        int ans = 0;
        loop(i, 1, n) ans += calc(i);
        cout << ans << '\n';
    }
}
namespace subtask2 {
    int calc(int s) {
        dp1[s] = 0, dp2[s] = 1;
        int cnt = 0;
        loop(i, s + 1, n) {
            if(l[i] <= s) dp1[i] = 1, dp2[i] = 1;
            else if(l[i] == i) return cnt;
            else {
                dp1[i] = dp1[l[i]] + 1, dp2[i] = 0;
                loop(j, l[i], min(i - 1, l[i] + 2)) {
                    if(dp1[j] != dp1[l[i]]) break;
                    dp2[i] += dp2[j];
                }
            }
            cnt += (dp2[i] == 2) * (n - i + 1);
        }
        return cnt;
    }
    void solve() {
        cin >> n >> d;
        loop(i, 1, n) cin >> a[i];
        int lp = 1;
        loop(rp, 1, n) {
            while(a[rp] - a[lp] > d) lp++;
            l[rp] = lp;
        }
        int ans = calc(1);
        cout << ans << '\n';
    }
}
// namespace subtask3 {
//     int find(vector<int>& a, int x) {
//         int l = -1, r = a.size();
//         while(l + 1 < r) {
//             if(a[mid] > x) r = mid;
//             else l = mid;
//         }
//         return a.size() - r;
//     }
//     int calc(int s) {
//         int p3 = s, v3 = 1, cnt3;
//         int p2 = -1, v2 = 0x3f3f3f3f, cnt2;
//         int p1 = -1, v1 = 0x3f3f3f3f, cnt1;
//         int lst = s, ans = 0;
//         vector<int> vec;
//         while(true) {
//             // cout << lst << '\n' << flush;
//             vec.clear();
//             int p = lst + 1;
//             while(p <= n && a[p] - a[lst] <= d) {
//                 vec.push_back(p);
//                 p++;
//             }
//             if(vec.size() == 0) return ans;
//             lst = p - 1;
//             cnt3 = p3 != -1 ? find(vec, a[p3] + d) : vec.size();
//             cout << lst << ' ' << p3 << ' ' << vec.size() << '\n' << flush;
//             assert(cnt3 == 0);
//             cnt2 = p2 != -1 ? find(vec, a[p2] + d) : vec.size();
//             cnt1 = p1 != -1 ? find(vec, a[p1] + d) : vec.size();
//             // 001
//             int x = v3, cnt = cnt2 - cnt3;
//             ans += cnt * (x == 2);
//             // 011
//             x = v3 + v2, cnt = cnt1 - cnt2;
//             ans += cnt * (x == 2);
//             // ----------------
//             int np1 = -1, np2 = -1, np3 = -1, nv1 = -1, nv2 = -1, nv3 = 0x3f3f3f3f;
//             if(vec.size() >= 1) {
//                 np3 = vec[vec.size() - 1];
//                 if(cnt3 >= 1) nv3 = 0, assert(0);
//                 else if(cnt2 >= 1) nv3 = v3;
//                 else if(cnt1 >= 1) nv3 = v3 + v2;
//                 else nv3 = v3 + v2 + v1;
//             }
//             if(vec.size() >= 2) {
//                 np2 = vec[vec.size() - 2];
//                 if(cnt3 >= 2) nv2 = 0, assert(0);
//                 else if(cnt2 >= 2) nv2 = v3;
//                 else if(cnt1 >= 2) nv2 = v3 + v2;
//                 else nv2 = v3 + v2 + v1;
//             } 
//             if(vec.size() >= 3) {
//                 np1 = vec[vec.size() - 3];
//                 if(cnt3 >= 3) nv1 = 0, assert(0);
//                 else if(cnt2 >= 3) nv1 = v3;
//                 else if(cnt1 >= 3) nv1 = v3 + v2;
//                 else nv1 = v3 + v2 + v1;
//             } 
//             v1 = nv1, v2 = nv2, v3 = nv3, p1 = np1, p2 = np2, p3 = np3;
//         }
//     }
//     void solve() {
//         cin >> n >> d;
//         loop(i, 1, n) cin >> a[i];
//         int ans = 0;
//         loop(i, 1, n) ans += calc(i);
//         cout << ans << '\n';
//     }
// }
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int c, t; cin >> c >> t; while(t--) {
        if(c <= 10) subtask1::solve();
        else if(c <= 12) subtask2::solve();
        else subtask1::solve();
    }
    return 0;
}