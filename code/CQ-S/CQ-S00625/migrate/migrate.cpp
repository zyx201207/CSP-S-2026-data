#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 5;
const int N1 = 5005;
int n, nxt[N];
LL a[N], d;
pair <int, int> dp[N1][N1];
vector <pair<int, int> > lis[N];
multiset <pair<int, int> > st;
void Insert(int cr, int x, int y) {
    //cerr<<"Insert "<<cr<<" "<<x<<" "<<y<<"\n";
    st.insert({ x,y });
    lis[cr + 1].push_back({ x,y });
}
void SolveBf() {
    LL ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++)
            lis[j].clear();
        st.clear();
        Insert(nxt[i], 1, 1);
        for (int j = i + 1;j <= n;j++) {
            for (auto pr : lis[j])
                st.erase(st.find(pr));
            if (st.empty())
                continue;
            auto it = st.begin();
            int sum = 0, mi = st.begin()->first;
            int cnt = 3;
            while (cnt-- && it != st.end() && it->first == mi)
                sum += it++->second;
            dp[i][j].first = mi;
            if (sum >= 3)
                dp[i][j].second = 3;
            else
                dp[i][j].second = sum;
            Insert(nxt[j], dp[i][j].first + 1, dp[i][j].second);
            //cout<<i<<" "<<j<<" "<<dp[i][j].first<<" "<<dp[i][j].second<<"\n";
            if (dp[i][j].second == 2) {
                //cerr<<i<<" "<<j<<"\n";
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
void SolveA() {
    //cerr << nxt[1] - 1 << "\n";
    if (nxt[1] == n || nxt[1] <= 2) {
        cout << 0 << "\n";
        return;
    }
    LL ans = 0;
    int d = nxt[1] - 1;
    for (int i = 1;i <= n;i++) {
        if (i + 2 * d - 1 > n)
            break;
        else
            ans++;
    }

    cout << ans << "\n";
}
void SolveB() {
    LL ans = 0;
    for (int p = 1;p <= n;p++)
        if (a[p] - a[1] <= d && a[n] - a[p] <= d) {
            for (int i = 1;i < p;i++) {
                int nj = nxt[nxt[i] - 1];
                int nk = (nxt[i] == 2 ? p : nxt[nxt[i] - 2]);
                ans += nj - nk;
            }
            break;
        }
    cout << ans << "\n";
}
void SolveC() {
    cout << 0 << "\n";
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
            cin >> a[i];
        int j = 1;
        for (int i = 1;i <= n;i++) {
            while (j <= n && a[j] - a[i] <= d)
                j++;
            nxt[i] = j - 1;
        }
        if (c <= 10)
            SolveBf();
        else if (c <= 12)
            SolveA();
        else if (c <= 14)
            SolveB();
        else
            SolveC();
    }
}
