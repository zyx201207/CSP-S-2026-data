#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int a, t, next[505], front_[505];
}arr[505][505];
ll l = 0, r = 0;
ll c, n, m, d, q, w[505], k[505], x, y; // n是地铁站的数量， m是地铁线路的数量，d代表每个地铁站最多被几条线路经过，p代表出行计划数 	
int dfs(int a, int gogogo) {//当前的位置 
	if(a == y) return gogogo;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < l; j++) {
			dfs(arr[k[i]][i].front_[j], gogogo + arr[k[i]][i].t);
		}
	}
	return 0;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0; i < m; i++) cin >> w[i];
	
	for(int i = 0; i < n; i++){
		cin >> k[i]; 
		
		for(int j = 0; j < k[i]; j++){
			cin >> arr[i][j].a >> arr[i][j].t;
		}
		for(int j = 1; j < k[i] - 1; j++){
			if(arr[i][j].front_[l] != 0) l ++; 
			if(arr[i][j].next[r] != 0) r ++; 
			arr[i][j].front_[l] = arr[i][j - 1].a;
			arr[i][j].next[r] = arr[i][j + 1].a;
		}
	}
	while(q --) {
		int time = 0;
		cin >> x >> y;
		time += w[x] + w[y];
		time += dfs(x, 0);
		cout << time;
	}
	return 0;
}
