#include<bits/stdc++.h>
using namespace std;



int c;
int n, m;
int v, u;

vector<int> aa[200005];

int vis[200005];
int vis1[200005];

struct ss1ss{
	int x;
	long long cnt;
	
	bool operator<(const ss1ss&other)const{
		return cnt > other.cnt;
	}
};

ss1ss x, y, z;
priority_queue<ss1ss> q;

int tot;
int shun[200005];

void aaaa(int x){
	for(auto vv : aa[x]){
		if(!shun[vv] && vis[vv]){
			shun[vv] = tot;
			aaaa(vv);
		}
	}
	
	return;
}

void init(){
	for(int i = 1; i <= n; i++){
		shun[i] = 0;
	}
	
	return;
}

int ans1;

void ssss(int x){
	if(x > m){
		tot = 0;
		
		for(int i = 1; i <= n; i++){
			if(!shun[i] && vis[i]){
				tot++;
				shun[i] = tot;
				aaaa(i);
			}
		}

		if(tot == 2){
			for(int i = 1; i <= n; i++){
				vis1[i] = 1e9;
				
				if(vis[i]){
					z.x = i;
					z.cnt = 0;
					vis1[i] = 0;
					
					q.push(z);
				}
			}
			
			while(!q.empty()){
				z = q.top();
				q.pop();
				
				if(vis1[z.x] != z.cnt){
					continue;
				}
				
				for(auto vv : aa[z.x]){
					y.x = vv;
					y.cnt = z.cnt + 1;
					
					if(vis1[y.x] <= y.cnt){
						continue;
					}
					
					vis1[y.x] = y.cnt;
					q.push(y);
				}
			}
			
			int asas = 0;
			for(int i = 1; i <= n; i++){
				asas = max(asas, vis1[i]);
			}
			
			ans1 = min(ans1, asas);
		}
		
		return;
	}
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			ssss(x + 1);
			vis[i] = 0;
		}
	}
	
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c;
	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		
		
		for(int i = 1; i <= n; i++){
			aa[i].clear();
		}
		
		for(int i = 1; i < n; i++){
			cin >> v >> u;
			aa[v].push_back(u);
			aa[u].push_back(v);
		}
		
		ans1 = 1e9;
		
		ssss(1);
		
		cout << ans1 << "\n";
	}
	
	
	
	
	return 0;
}

/*

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
