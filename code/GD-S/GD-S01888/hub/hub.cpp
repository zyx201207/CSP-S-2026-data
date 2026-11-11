#include<bits/stdc++.h>
using namespace std;
int c , T , n , k , ans = 1e9;
int dis[100005];
int uu[100005] , vv[100005] , fa[100005] , mark[100005];
vector<int> vec[200005] , vec2[200005];
int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void calc(int x , int fa){
	dis[x] = min(dis[x] , dis[fa] + 1);
	for(auto i : vec[x]){
		if(i == fa) continue;
		calc(i , x);
	}
}
void dfs(int x , int po){
	if(po > k) return ;
	if(x > n){
		if(po != k) return ;
		for(int i = 0 ; i <= n ; i++) vec2[i].clear();
		for(int i = 1 ; i <= n ; i++) fa[i] = i , dis[i] = 1e9;
		int ch = 0;
		for(int i = 1 ; i < n ; i++){
			if(mark[uu[i]] == 1 && mark[vv[i]] == 1){
				if(find(uu[i]) != find(vv[i])){
					fa[find(uu[i])] = find(vv[i]);
					ch++;
				}
			}
		}
		if(ch < k - 2) return ;
		//for(int i = 1 ; i <= n ; i++) cout << mark[i] << " ";
	//	cout << "\n";
		for(int i = 1 ; i <= n ; i++){
			if(mark[i] == 0) continue;
			dis[i] = 0;
			calc(i , 0);
		}	
	//	for(int i = 1 ; i <= n ; i++) cout << dis[i] << " ";
	//	cout << "\n";
		int maxn = 0;
		for(int i = 1 ; i <= n ; i++) maxn = max(maxn , dis[i]);
		ans = min(ans , maxn);
		return ;
	}
	mark[x] = 1;
	dfs(x + 1 , po + 1);
	mark[x] = 0;
	dfs(x + 1 , po);
}
int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> c >> T;
	while(T--){
		ans = 1e9;
		cin >> n >> k;
		for(int i = 1 ; i < n ; i++){
			int u , v;
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
			uu[i] = u , vv[i] = v;
		}
		dfs(1 , 0);
		cout << ans << "\n";
		for(int i = 0 ; i <= n ; i++) vec[i].clear();
	}
	return 0;
}
//x 2x 3x 4x 5x
