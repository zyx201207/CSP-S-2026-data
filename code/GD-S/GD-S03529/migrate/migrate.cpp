#include<bits/stdc++.h>
using namespace std;
struct node {
	long long x , step;
};
long long w[2000005] , ans , N , d;
bool vis[2000005];
void bfs(long long n , long long m) {
	long long minn = INT_MAX , t = 0;
	queue<node> q;
	q.push({n , 0});
	memset(vis , 0 , sizeof(vis));
	while(q.size()) {
		node f = q.front();
		vis[f.x] = 1;
		q.pop();
		if(f.x == m)
			if(minn == INT_MAX) minn = f.step , t++;
			else if(minn == f.step) t++;
		if(minn != INT_MAX) continue;
		for(int i = 1; i <= N; i++) {
			if(vis[i] == 0 && abs(w[f.x] - w[i]) <= d)
				q.push({i , f.step + 1});
		}
	}
	if(t == 2)
		ans++;
	return;
}
void work() {
	ans = 0;
	cin >> N >> d;
	for(int i = 1; i <= N; i++)
		cin >> w[i];
	for(int i = 1; i <= N; i++)
		for(int j = i; j <= N; j++)
			bfs(i , j);
	cout << ans << "\n";
}
int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	long long c , q;
	cin >> c >> q;
	while(q--) {
		work();
	} 
	return 0;
}
