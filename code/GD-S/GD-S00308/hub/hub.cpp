#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
const int INF = 1e18;
vector<int> vc[N];
int vis[N], in[N], a[N], b[N], c, t, n, k, ans;
void bfs(int x){
	int K = k;
	for(int i = 1; i < n; i++){
		if(i == x) continue;
		vc[a[i]].push_back(b[i]);
		vc[b[i]].push_back(a[i]);
		in[a[i]]++, in[b[i]]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(in[i] == 1) q.push(i);
	int cnt = 0;
	while(!q.empty()){
		int s = q.size();
		cnt++;
		if(K == 0){
			ans = 0;
			return ;
		}
		while(s--){
			int tmp = q.front();
			q.pop();
			vis[tmp] = 1;
			K--;
			if(K == 0){
				ans = min(ans, cnt);
				break;
			}
			for(int i = 0; i < vc[tmp].size(); i++){
				int v = vc[tmp][i]; 
				in[v]--;
				if(!vis[v] && in[v] <= 1) q.push(v);
			}
		}
		if(K == 0) break;
	}
	memset(vis, 0, sizeof(vis));
	memset(in, 0, sizeof(in));
	for(int i = 1; i <= n; i++) vc[i].clear();
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		k = n - k;
		ans = INF;
		for(int i = 1; i < n; i++) cin >> a[i] >> b[i];
		for(int i = 0; i < n; i++) bfs(i);
		cout << ans << endl;
	}
	return 0;
}
