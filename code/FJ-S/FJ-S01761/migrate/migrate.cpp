#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5005;
int n,d,x[N],cid,T,dis[N],cnt[N];
vector<int> v[N];

inline void bfs(int st){
	memset(dis,-1,sizeof dis);
	memset(cnt,0,sizeof cnt);
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : v[u]){
			if(dis[i] != -1) continue;
			dis[i] = dis[u] + 1;
			q.push(i);
		}
	}
	q.push(st);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : v[u]){
			if(dis[i] == dis[u] + 1){
				cnt[i]++;
				q.push(i);
			}
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> cid >> T;
	while(T--){
		int ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
			v[i].clear();
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if(x[j] - x[i] <= d){
					v[i].push_back(j);
//					deg1[i]++;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			bfs(i);
			ans += count(cnt+1,cnt+n+1,2);
		}
		cout << ans << '\n';
	}

	return 0;
}