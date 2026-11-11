#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10;
const ll INF = 1e18;
const int mod = 1e9 + 7;
#define pii pair<ll , ll>

int n , d , x[N];
vector<int> e[N];
bool vis[N];

ll minx = INF , res = 0;
void path(int pos , int des , int dis){
	if(pos == des){
		if(minx == dis) res++;
		else if(minx > dis){
			minx = dis;
			res = 1;
		}
		return ;
	} 
	vis[pos] = 1;
	for(int i = 0 , v ; i < e[pos].size() ; i++){
		v = e[pos][i];
		if(!vis[v]) path(v , des , dis + 1);
	}
	vis[pos] = 0;
	return ;
}

int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c , T;
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++){
			cin >> x[i];
			e[i].clear();
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				if(abs(x[i] - x[j]) <= d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				minx = INF , res = 0;
				path(i , j , 0);
				if(res == 2){
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
} 


/*
FC /W D:\GD-S04703\subway\subway.ans D:\GD-S04703\subway\subway.out

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
