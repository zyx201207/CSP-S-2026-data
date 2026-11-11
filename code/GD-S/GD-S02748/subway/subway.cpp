#include<bits/stdc++.h>
using namespace std;

struct node{
	int num, t;
	
	node(){}
	node(int num1, int t1){
		num = num1;
		t = t1;
	}
};

int c, n, m, d, q;

int w[510];
int a[510][510];
vector<node> val[510];

bool vis[510];

void bfs(int x, int y){
	
	queue<int> q;
	q.push(x);
	
	for(int i = 1; i <= m; i++){
		vis[i] = false;
	}
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		if(vis[now] == true) continue;
		vis[now] = true;
		
		
		
	}
	
	return ;
}

int main(){
	
	freopen("subway.in", "w", stdin);
	freopen("subway.out", "r", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		
		int t = 0;
		while(k--){
			int x;
			cin >> x;
			cin >> a[x][i];
			
			if(t){
				val[i].push_back( node(x, a[x][i] + a[t][i]) );
			}
			else t = x;
		}
		
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		
		bfs(x, y);
	}
	
	return 0;
}
