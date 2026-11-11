#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[25004];
int timem__[555][665];
pair<int, int> st; 
vector<pair<int, int> > E[25005];
vector<pair<int, int> > G[666];
int shor[666][666];
int BFS(int x, int y){
	queue<pair<int, int > > q;
	int ans = 0;
	for(auto u : G[x]){
		q.push(u);
		
	}
		cout << q.empty()<< endl;
	while(!q.empty()){
		cout << 9 <<endl;
		pair<int, int> tmp = q.front();
		q.pop();
		ans += tmp.second;
		
		if(tmp.first == y)return ans;
		for(auto kk : G[tmp.first]){
			if(ans + timem__[kk.first][tmp.first] < shor[x][kk.first]){
				q.push(kk);
				shor[x][kk.first] = ans + timem__[kk.first][tmp.first];
			}
		
		}
		ans -= tmp.second;
	}
}
signed main(){
	int c, n, m, d, q;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m ; i++){
		for(int j = 1; j <= m; j++){
			timem__[i][j] = 1e12+9;
			shor[i][j] = 1e12 + 9;
		}
	}
//	cout << "!"<< endl;
	for(int i = 1; i <= m; i++)cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			E[tmp1].push_back({tmp2, k});
		}
	}
//	cout << "!"<< endl;
	for(int i = 1; i <= m; i++){
		for(auto u : E[i]){
			for(auto v : E[i]){
			cout << u.first <<' '<<v.first<<endl;
				if(u.first == v.first)continue;
				
				if(u.second + v.second < timem__[u.first][u.first]){
					timem__[u.first][v.first] = u.second + v.second;
					timem__[v.first][u.second] = u.second + v.second;
					//	cout << "!!!!!!!!!!!!!!";
				}	
			}
		}
	}
//	cout << "!"<< endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(timem__[j][i] == 1e17 + 9)continue;
			else{
				G[i].push_back({j, timem__[i][j]});
				G[j].push_back({i, timem__[j][i]});
		
			}
		}
	}
//	cout << "!"<< endl;
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		int ans = 1e17 + 9;
		for(auto u : E[x]){
			for(auto v : E[y]){
				ans = min(ans, BFS(u.first, v.first) + a[x] + a[x] + u.first + v.first);
			}
		}
//		ans += a[x] + b[x];
		cout << x + y << endl;
	}
}

