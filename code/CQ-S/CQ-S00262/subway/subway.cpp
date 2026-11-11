#include<bits/stdc++.h>
using namespace std;

int c;
int w;
int n, m;
int v, u;
int d, qq;

int k[505];
long long a[500005];

long long ans1[505][505];
long long vis[505];

vector<pair<int, long long>> aa[505];
vector<pair<int, long long>> really_aa[505];

struct ssss{
	int x;
	long long cnt;
	
	bool operator<(const ssss&other)const{
		return cnt > other.cnt;
	}
};

ssss x, y, z;
priority_queue<ssss> q;

vector<pair<int, long long>> dtx[500005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c;
	cin >> m >> n;
	cin >> d >> qq;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= m; i++){
		cin >> k[i];
		
		for(int j = 1; j <= k[i]; j++){	
			cin >> v >> w;
			aa[i].push_back({v, w});
			dtx[v].push_back({i, w});
		}
	}
	
	for(int i = 1; i <= m; i++){
		for(auto vv : aa[i]){
			for(auto vvv : dtx[vv.first]){
				really_aa[i].push_back({vvv.first, vv.second + vvv.second});
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		for(int i = 1; i <= m; i++){
			vis[i] = 1e18;
		}
		
		vis[i] = 0;
		x.x = i;
		x.cnt = 0;
		
		q.push(x);
		
		while(!q.empty()){
			x = q.top();
			q.pop();
			
			if(vis[x.x] != x.cnt){
				continue;
			}
			
			for(auto vv : really_aa[x.x]){
				y.x = vv.first;
				y.cnt = x.cnt + vv.second;
				
				if(vis[y.x] <= y.cnt){
					continue;
				}
				
				vis[y.x] = y.cnt;
				q.push(y);
			}
		}
		
		for(int j = 1; j <= m; j++){
			ans1[i][j] = vis[j];
		}
	}
	
	while(qq--){
		cin >> v >> u;
		
		long long really_ans1 = 1e18;
		
		for(auto vv : dtx[v]){
			for(auto vvv : dtx[u]){
				really_ans1 = min(really_ans1, ans1[vv.first][vvv.first] + vv.second + vvv.second);
			}
		}
		
		cout << really_ans1 + a[v] + a[u] << "\n";
	}
	
	return 0;
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
