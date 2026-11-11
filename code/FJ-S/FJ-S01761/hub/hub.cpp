#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 15,NN = 1005;
int cid,T,n,k,d[NN],ans;
vector<int> v[NN];
bool ins[N];

inline void bfs(){
	memset(d,-1,sizeof d);
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(ins[i]){
			q.push(i);
			d[i] = 0;
		}
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : v[u]){
			if(d[i] != -1) continue;
			d[i] = d[u] + 1;
			q.push(i);
		}
	}
}

inline void bfs1(int x,int y){
	memset(d,-1,sizeof d);
	queue<int> q;
	d[x] = d[y] = 0;
	q.push(x);
	q.push(y);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i : v[u]){
			if(d[i] != -1) continue;
			d[i] = d[u] + 1;
			q.push(i);
		}
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> cid >> T;
	while(T--){
		ans = INT_MAX;
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			v[i].clear();
		}
		for(int i = 1;i < n;i++){
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(cid == 7){
			for(int i = 1;i <= n;i++){
				for(int j = i+1;j <= n;j++){
					bfs1(i,j);
					ans = min(ans,*max_element(d+1,d+n+1));
				}
			}
			cout << ans << '\n';
		}
		else{
			for(int mask = 1;mask < (1 << n);mask++){
				if(__builtin_popcount(mask) != k) continue;
				for(int i = 0;i < n;i++){
					ins[i+1] = (mask & (1 << i));
				}
				int cnt = 0;
				for(int i = 1;i <= n;i++){
					if(!ins[i]) continue;
					for(int j : v[i]){
						if(j < i) continue;
						if(ins[j]) cnt++;
					}
				}
				if(k - cnt > 2) continue;
				bfs();
				ans = min(ans,*max_element(d+1,d+n+1));
			}
			cout << ans << '\n';
		}
	}

	return 0;
}