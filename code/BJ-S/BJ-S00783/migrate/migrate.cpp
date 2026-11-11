#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (b); i >= (a); i--)
#define rp(i, a) for(int i = 1; i <= (a); i++)
#define pr(i, a) for(int i = (a); i >= 1; i--)
#define ll long long
#define db double
#define pb push_back
#define si(x) (int)(x).size()
#define ft first
#define sd second
#define pii pair<int, int>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define endl '\n'
const ll Mod = 1000000007ll;
//const ll Mod = 998244353ll;
const ll B = 13131ll;

int c, T, n;
ll d;
ll a[2000005];
ll b[2000005];
int sz, sum;
vector<int> pos;
void dfs(int x) {
    if(x == sz - 1) {
        if(llabs(a[b[x]] - a[b[x - 1]]) <= d) {
            sum++;
        }
        return;
    }
//    cout << "x = " << x << ", range: " << max(1, pos[x] - 2) << ", " << min(n, pos[x] + 2) << endl;
    rep(y, max(1, pos[x] - 2), min(n, pos[x] + 2)) {
        b[x] = y;
//        cout << "b[" << x << "] = " << y << endl;
        if(llabs(a[y] - a[b[x - 1]]) <= d) {
            dfs(x + 1);
        }
        if(sum > 2) {
            return;
        }
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--) {
        cin >> n >> d;
        rp(i, n) {
            cin >> a[i];
        }
        int ans = 0;
        rp(i, n) {
            int ii = i;
            pos = {i};
            rep(j, i + 1, n) {
//                cout << "i = " << i << ", j = " << j << endl;
                if(a[j] - a[ii] > d) {
                    int iii = ii;
//                    cout << "right move" << endl;
                    while(a[ii + 1] - a[iii] <= d) {
                        ii++;
                    }
                    pos.push_back(ii);
//                    cout << "move to " << ii << endl;
//                    if(a[ii] - a[i] > d) {
//                        cout << "fail move" << endl;
//                        break;
//                    }
                }
                pos.push_back(j);
                sz = pos.size();
//                cout << "pos :" << sz << endl;
//                for(int k : pos) {
//                    cout << k << " ";
//                }
//                cout << endl;
                b[0] = pos[0];
                b[sz - 1] = pos[sz - 1];
                sum = 0;
                dfs(1);
//                cout << "sum = " << sum << endl;
                if(sum == 2) {
//                    cout << "(" << i << ", " << j << endl;
                    ans++;
                }
                pos.pop_back();
            }
        }
        cout << ans << endl;
    }
    return 0;
}
