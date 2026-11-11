#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define pii pair<int, long long>
const int maxn = 5e5 + 10;
const long long INF = 9e18 + 10;
int c, n, m, d, st, ed, q, a[maxn], t[maxn], w[maxn];
bool vis[maxn];
long long ans;
vector<pii> g[maxn];
void dfs(int s, int ed, long long sum){
    //cerr << s << " " << sum << endl;
    if(s == ed){
        ans = min(ans, sum);
        return;
    }
    vis[s] = true;
    for(auto x : g[s]){
        if(!vis[x.first]) dfs(x.first, ed, sum+x.second);
    }
    vis[s] = false;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> a[j] >> t[j];
            for(int f = 1; f < j; f++){
                g[a[f]].push_back({a[j], t[f] + t[j]});
            }
        }
    }
    while(q--){
        ans = INF;
        int st, ed;
        cin >> st >> ed;
        //cerr << st << " " << ed << endl;
        dfs(st, ed, 0ll);
        cout << ans+w[st]+w[ed] << endl;
    }
}
