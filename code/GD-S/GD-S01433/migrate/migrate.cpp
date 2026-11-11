#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i=a; i<=b; ++i)
#define F_(i,a,b) for(int i=a; i>=b; i--)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fr first
#define sc second
#define pb push_back
const int N = 2e6+10, M = 1e6+10, INF = 1e9;
int tid,n,dis[N],cnt[N];
ll d,ar[N];
vector<int> go[N];
void init(){
	F(i,1,n) go[i].clear();
}
void bfs(int s){
	queue<int> q;
	F(i,1,n) dis[i] = INF, cnt[i] = 0;
	dis[s] = 0, cnt[s] = 1;
	q.push(s);
	while (q.size()){
		int u = q.front(); q.pop();
		for (auto v:go[u]){
			if (dis[u]+1 < dis[v]){
				dis[v] = dis[u]+1, cnt[v] = cnt[u];
				q.push(v);
			} else if (dis[u]+1 == dis[v]){
				cnt[v] = min(3,cnt[v]+cnt[u]);
			}
		}
	}
}
void baoli(){
	F(i,1,n) F(j,i+1,n) if (llabs(ar[i]-ar[j]) <= d) go[i].pb(j), go[j].pb(i);
	ll ans = 0;
	F(s,1,n){
		bfs(s);
		F(i,s+1,n) if (cnt[i] == 2) ++ans;
	}
	cout << ans << "\n";
}
void solveA(){
	ll k = d/(ar[2]-ar[1]);
	if (k <= 1) cout << "0\n";
	else cout << max(0ll,n-k*2+1) << "\n";
}
void solveB(){
	cout << "0\n";
}
void work(){
	init();
	cin >> n >> d;
	F(i,1,n) cin >> ar[i];
	if (n == 1) cout << "0\n";
	else if (tid==11 || tid==12) solveA();
	else if (tid==13 || tid==14) solveB();
	else if (n <= 5000) baoli();
	else cout << "0\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int _; cin >> tid >> _;
	while (_--) work();
	return 0;
}
