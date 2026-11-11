#include <bits/stdc++.h>
using namespace std;
#define int long long

const int NR = 2e6 + 5;
int n, d, c;
int a[NR];
vector<pair<int, int> > g;

void init()
{
    g.clear();
}

int minpath = 9e18;
void dfs2(int x, int y, int cnt){
    if(cnt >= minpath) return ;
    if(x == y){
        minpath = min(minpath, cnt);
        return ;
    }
    for(int nx = x+1; a[nx] <= a[x]+d && nx <= y; nx ++){
        dfs2(nx, y, cnt+1);
    }
}

int cnt = 0;
void dfs(int x, int y, int len)
{
    if(x > y) return ;
    if(x == y){
        if(len == minpath) cnt ++;
        return ;
    }
    for(int nx = x+1; a[nx] <= a[x]+d && nx <= y; nx ++){
        dfs(nx, y, len+1);
    }
}

void sub1()
{
    int ans = 0;
    for(int x = 1; x <= n; x ++){
        for(int y = x+1; y <= n; y ++){
            cnt = 0, minpath = 9e18;
            dfs2(x, y, 0);
            dfs(x, y, 0);
            // cout << x << ' ' << y << ' ' << minpath << ' ' << cnt << '\n';
            if(cnt == 2) ans ++;
        }
    }
    cout << ans << endl;
}

void greedy()
{

    for(int i = 1; i <= n; i ++){
        int R = upper_bound(a+i+1, a+n+1, a[i]+d)-a-1;
        for(int j = i+1; j <= n; j ++){
            if(a[i] + d >= a[j]) continue;
            if(a[i] + d+d < a[j]) break;
            int L = lower_bound(a+i+1, a+j+1, a[j]-d)-a;
            if(R-L+1 < 2) break;
            if(R-L+1 == 2) g.push_back(make_pair(i, j));
        }
    }
    for(int i = 0; i < g.size(); i ++){
        auto now = g[i];
        int l = now.first, r = now.second;
        //if(i == g.size()-1)
    }
    cout << -1 << endl;
}

void solve()
{
    cin >> n >> d;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sub1();
    init();
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T;
    cin >> c >> T;
    while(T --){
        solve();
    }
    return 0;
}
