#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int c, t, n;
unsigned int d;
unsigned int pos[N];
int tree[N], x[N];

int query(int p){
    int ans = 0;
    for (int i = p; i > 0; i -= (i & -i))
        ans += tree[i];
    return ans;
}

void add(int p, int x){
    for (int i = p; i <= n + 1; i += (i & -i))
        tree[i] += x;
}

void solve(int x){
    memset(tree, 0, sizeof(int) * (n + 2));
    queue<int> q;
    q.push(x), add(x, 1), add(x + 1, -1);
    int r = x;
    while (!q.empty()){
        queue<int> q2;
        int nr = r;
        while (!q.empty()){
            int p = q.front();
            q.pop();
            int k = query(p);
            while (nr < n && pos[nr + 1] - pos[p] <= d)
                nr++, q2.push(nr);
            add(r + 1, k), add(nr + 1, -k);
        }
        q = q2, r = nr;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if (c <= 10){
        while (t--){
            cin >> n >> d;
            for (int i = 1; i <= n; i++)
                cin >> pos[i];
            int ans = 0;
            for (int i = 1; i <= n; i++){
                solve(i);
                for (int j = i; j <= n; j++)
                    if (query(j) == 2)
                        ans++;
            }
            cout << ans << endl;
        }
    }
    else if (c == 11 || c == 12){
        while (t--){
            cin >> n >> d;
            for (int i = 1; i <= n; i++)
                cin >> pos[i];
            int ans = 0;
            solve(1);
            for (int i = 1; i <= n; i++)
                if (query(i) == 2)
                    ans += (n - i + 1);
            cout << ans << endl;
        }
    }
    else {
         while (t--){
            cin >> n >> d;
            for (int i = 1; i <= n; i++)
                cin >> pos[i];
            int r = 1, ans = 0;
            for (int i = 1; i <= n; i++){
                while (r < n && pos[r + 1] - pos[i] <= d)
                    r++;
                if (r == i + 2){
                    int p = upper_bound(pos + 1, pos + n + 1, pos[r - 1] + d) - pos - 1;
                    ans += p - r;
                }
                else if (r > i + 2){
                    int p = upper_bound(pos + 1, pos + n + 1, pos[r - 1] + d) - pos;
                    int q = upper_bound(pos + 1, pos + n + 1, pos[r - 2] + d) - pos;
                    ans += p - q;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

