#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long LO;
typedef unsigned int uint;
const int N = 4003, SHUFFLE = 500000;
int cc0, t;
int n, k;
vector<int> g[N];
int S[N], ans;
int dist[N][N];
bool st[N], SS[N];

uint seed = 114514;
uint _rand(){
	seed ^= (seed>>13);
	seed ^= (seed<<17);
	seed ^= (seed>>5);
	return seed;
}

void search(int st, int x, int step, int fa){
	for(const int& v:g[x]){
		if(v == fa) continue;
		dist[st][v] = step;
		search(st, v, step+1, x);
	}
	return ;
}

void search2(int x){
	st[x] = true;
	for(const int& v:g[x]){
		if(SS[v]&&(!st[v])){
			search2(v);
		}
	}
	return ;
}

bool check(){
	memset(st, false, sizeof st);
	int cnt = 0;
	for(int i = 1;i <= n;++i){
		if(SS[i]&&(!st[i])){
			++cnt;
			if(cnt > 2){
				return false;
			}
			search2(i);
		}
	}
	return true;
}

void upd(){
	if(check()){
		int maxx = -1;
		for(int i = 1;i <= n;++i){
			int minx = 2e9;
			for(int j = 1;j <= k;++j){
				minx = min(minx, dist[S[j]][i]);
			}
			maxx = max(minx, maxx);
		}
		ans = min(ans, maxx);
	}
	return ;
}

void dfs(int x, int cnt){
	if(cnt == k + 1){
		upd();
		return ;
	}
	if(x == n + 1){
		return ;
	}
	//Ñ¡x
	S[cnt] = x; SS[x] = 1;
	dfs(x + 1, cnt + 1);
	S[cnt] = 0; SS[x] = 0;
	//²»Ñ¡x
	dfs(x + 1, cnt);
	return ; 
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> cc0 >> t;
	while(t--){
		ans = 2e9;
		cin >> n >> k;
		for(int i = 1;i <= n;++i){
			g[i].clear();
		}
		memset(SS, 0, sizeof SS);
		for(int i = 1, u, v;i <= n-1;++i){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i = 1;i <= n;++i){
			search(i, i, 1, -1);
		}
		if(n <= 8){
			dfs(1, 1);
		}else{
			for(int i = 1;i <= n;++i)
				S[i] = i;
			for(int i = 1;i <= k;++i){
				SS[i] = 1;
			}
			for(int i = 1, j, tmp;i <= SHUFFLE;++i){
				j = _rand()%k+1;
				tmp = _rand()%(n-k)+k+1;
				SS[S[j]] = 0;
				SS[S[tmp]] = 1;
				swap(S[j],S[tmp]);
				upd();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

