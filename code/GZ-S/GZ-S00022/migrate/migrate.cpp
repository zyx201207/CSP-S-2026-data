//GZ-S00022 云岩区实验中学 向子睿
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5010, inf = 0x3f3f3f3f;
#define fi first
#define se second
#define pii pair<int, int>
int c, t, n = maxn-1, d, x[maxn], ans;
signed dis[maxn][maxn], cnt[maxn][maxn];

void bfs(int st){
    queue<pii> q;
    q.push(make_pair(st, 0));
    while(q.size()){
        pii t = q.front();
        q.pop();
        if(t.se > dis[st][t.fi])continue;
        if(t.se == dis[st][t.fi]){
            cnt[st][t.fi]++;
            if(cnt[st][t.fi] > 3)continue;
        }else{
            dis[st][t.fi] = t.se;
            cnt[st][t.fi] = 1;
        }for(int i = 1; i <= n; i++){
            if(llabs(x[t.fi] - x[i]) <= d){
                q.push(make_pair(i, t.se+1));
            }
        }
    }
}

void solve(){
    if(c <= 10){
            for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = inf;
                cnt[i][j] = 0;
            }
        }
    }cin >> n >> d;
    ans = 0;
    for(int i = 1; i <= n; i++)cin >> x[i];
    if(c > 10){
        cout << "0\n";
        return ;
    }for(int i = 1; i <= n; i++)bfs(i);
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(cnt[i][j] == 2)ans++;
        }
    }cout << ans << '\n';
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
        solve();
	}
	return 0;
}
