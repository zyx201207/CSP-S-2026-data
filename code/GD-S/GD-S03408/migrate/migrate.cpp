# include <iostream>
# include <vector>
# include <queue>
# define iL inline
# define ll long long
# define MULTEST
# define FILE
using namespace std;
const int N10 = 5e3 + 3,N = 2e6 + 6;
int n; ll d,a[N];
vector<int> adj[N10]; int dis[N10],cnt[N10];
iL void solve1(){
	int ans = 0;
	cin >> n >> d;
	for (int i = 1;i <= n;i++)
		cin >> a[i],adj[i].clear();
	for (int l = 1,r = 1;l <= n;l++){
		while (r <= n && a[r] - a[l] <= d) r++;
		for (int i = l + 1;i < r;i++)
			adj[l].push_back(i),
			adj[i].push_back(l);
	}for (int u = 1;u <= n;u++){
		queue<pair<int,int>> q;
		for (int i = u;i <= n;i++)
			cnt[i] = 0,dis[i] = N;
		q.push({u,0});
		while (!q.empty()){
			auto qwq = q.front();
			q.pop();
			int v = qwq.first,w = qwq.second;
			if (w > dis[v]) continue;
			if (w == dis[v]) cnt[v]++;
			else cnt[v] = 1;
			dis[v] = w;
			for (int qvq : adj[v])
				q.push({qvq,w + 1});
		}for (int i = u;i <= n;i++)
			ans += cnt[i] == 2;
	}cout << ans << '\n';
}iL void solve2(){
	cin >> n >> d;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (a[2] - a[1] >= d)
		cout << "0\n";
	else
		cout << max(0ll,n - ((d / (a[2] - a[1])) << 1) + 1) << '\n';
}iL void solve3(){
	cin >> n >> d;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	cout << "0\n"; // Maybe?
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	# ifdef FILE
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	# endif
	int ty,___ = 1;
	cin >> ty;
	# ifdef MULTEST
	cin >> ___;
	# endif
	while (___--){
		if (ty <= 10) solve1();
		else if (ty <= 12) solve2();
		else if (ty <= 14) solve3();
		else solve1();
	}return 0;
}

