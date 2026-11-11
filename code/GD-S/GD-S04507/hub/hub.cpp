#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int c , t;
vector <int> e[N];
int a[N];
bool mark[N];
bool vis[N];
int dis[N][N];
int ans = 1e9;
int d(int s , int k){
	bool vis[N] = {};
	queue <int> q;
	q.push(s);
	vis[s] = 1;
	dis[s][s] = 0;
	while(!q.empty()){
		int nxt = q.front();
		q.pop();
		for(int i = 0 ; i < e[nxt].size() ; i++){
			int xx = e[nxt][i];
			if(!vis[xx]){
				vis[xx] = 1;
				q.push(xx);
				dis[s][xx] = dis[s][nxt] + 1;
			}
		}
	}
	int r = 1e9;
	for(int i = 1 ; i < k ; i++){
		r = min(r , dis[s][a[i]]);
	}
	return r;
}
void flood(int x){
	queue <int> q;
	q.push(x);
	vis[x] = 1;
	while(!q.empty()){
		int nxt = q.front();
		q.pop();
		for(int i = 0 ; i < e[nxt].size() ; i++){
			int xx = e[nxt][i];
			if(mark[xx] && !vis[xx]){
				vis[xx] = 1;
				q.push(xx);
			}
		}
	}
}
bool CheckPNum(int k){
	memset(vis , 0 , sizeof vis);
	int r = 0;
	for(int i = 1 ; i < k ; i++){
		if(!vis[a[i]]){
			flood(a[i]);
			r++;
			if(r > 2){
				return 0;
			}
		}
	}
//	cout << r << " ";
	return 1;
}
void dfs(int k , int p , int n , int m){
	if(k > m){
//		for(int i = 1 ; i < k ; i++){
//			cout << a[i] << " ";
//		}
//		cout << ":";
//		cout << CheckPNum(k) << "\n";
		if(CheckPNum(k)){	//合理的方案 
			int now = -1e9;
			for(int i = 1 ; i <= n ; i++){
				now = max(now , d(i , k));
			}
//			cout << now << "-\n";
			if(now != -1e9) ans = min(ans , now);
//			cout << d(6 , k);
		}
//		cout << "\n";
	}else{
		for(int i = p + 1 ; i <= n ; i++){
			a[k] = i;
			mark[i] = 1;
			dfs(k + 1 , i , n , m);
			mark[i] = 0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin >> c >> t;
	while(t--){
		memset(mark , 0 , sizeof mark);
		memset(vis , 0 , sizeof vis);
		ans = 1e9;
		int n , k;
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i++){
			e[i].clear();
		}
		for(int i = 1 ; i <= n - 1 ; i++){
			int ui , vi;
			cin >> ui >> vi;
			e[ui].push_back(vi);
			e[vi].push_back(ui);
		}
		dfs(1 , 0 , n , k);
		cout << ans << "\n";
	}
	return 0;
} 
/*
0 1
7
4
1 2
1 3
2 4
2 5
3 6
3 7
*/
