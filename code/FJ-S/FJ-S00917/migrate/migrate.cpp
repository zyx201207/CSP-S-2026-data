#include<bits/stdc++.h>
using namespace std;
const int man = 2000005;
const int INF = 0x3f3f3f3f;
using ll = long long;

vector<int> g[man];
vector<bool> used(man);
vector<int> de(man);
ll cnt[man];

ll bfs(int s){
	fill(cnt,cnt + man,0);
	fill(used.begin(),used.end(),0);
	fill(de.begin(),de.end(),INF);
	queue<pair<int,int>> d;
	d.push({s,0});
	cnt[s] = 1;
	de[s] = 0;
	ll ans1 = 0;
	
	while(!d.empty()){
		auto cur = d.front();
		d.pop();
		int it = cur.first;
		int fa = cur.second;
		
		if(used[it] == 1) continue;
		used[it] = 1;
		if(cnt[it] == 2) {
			//cout << it << " ";
			ans1++;
		}
		
		for(int i : g[it]){
			if(de[i] == de[it]) continue;
			de[i] = min(de[it] + 1,de[i]);
			cnt[i] += cnt[it];
			d.push({i,it});
		}
	}
	return ans1;
}


void work(){
	int n;
	ll d;
	cin >> n >> d;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n - 1; ++i){
		//cout << i << "     " ;
		for(int j = i + 1; j <= n; ++j){
			if(a[j] - a[i] <= d){
				g[i].push_back(j);
				//cout << j << " ";
			}
			else{
				break;
			}
		}
		//cout << '\n';
	}
	ll ans = 0;
	for(int i = 1; i <= n - 1; ++i){
		//cout << bfs(i) << " ";
		ans += bfs(i);
	}
	
	cout << ans << '\n';
	for(int i = 1; i <= n - 1; ++i){
		g[i].clear();
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,q;
	cin >> c >> q;
	while(q--) work();
	return 0;
}
