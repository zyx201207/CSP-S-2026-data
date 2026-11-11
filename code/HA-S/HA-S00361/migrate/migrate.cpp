#include<bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;
ll read(){
	ll t = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return f * t;
}
ll n, d;
int  ICS;
const int N = 2e6 + 10;
ll a[N];
int fa[N];
vector<int> e[N];
int dis[3][3][N];
int dep[N];
inline int calc(int a, int b, int c, int op, int len){
	if(op == 1){
		//Ω·Œ≤∂Œ « 1 
		if(b - a == 1){
			return dis[1][min(2, c - b)][b];
		}
		if(b - a == 2){
			if(len == 2){
				int op = (1 + (fa[a + 1] == c));
				int len = (op == 1 ? c - fa[a + 1] : c - b); len = min(len, 2);	
				return dis[op][len][b] + fa[a + 1] - b;
			}
			else{
				if(fa[a + 1] == c){
					//π±œ◊ 0 ∏ˆ
					return 0; 
				}
				int op = (1 + (fa[a + 1] == c));
				int len = (op == 1 ? c - fa[a + 1] : c - b); len = min(len, 2);		
				return dis[op][len][b];
			}
		}
		if(len == 1){
			if(fa[b - 1] == c){
				//π±œ◊ 0 ∏ˆ
				return 0; 
			}
			int op = (1 + (fa[b - 1] == c));
			int len = (op == 1 ? c - fa[b - 1] : c - b); len = min(len, 2);	
			return dis[op][len][b];
		}
		if(fa[b - 1] == c){
			//π±œ◊ 0 ∏ˆ
			if(fa[b - 2] == c)
				return 0; 
			int op = 2;
			int len = c - fa[b - 2]; len = min(len, 2);
			return dis[op][len][b] + fa[b - 1] - fa[b - 2];
		}
		else{
			int op = 1;
			int len = c - fa[b - 1]; len = min(len, 2);
			return dis[op][len][b] + fa[b - 1] - fa[b - 2];	
		}
	}
	else{
		if(b - a == 1){
			return dis[2][min(2, c - b)][b] + c - b;
		}
		if(fa[b - 1] == c) return 0;
		int op = 2;
		int len = c - fa[b - 1]; len = min(len, 2);
		return dis[op][len][b] + fa[b] - fa[b - 1];
	}
}
long long ans;
void dfs(int now, int ff){
	dep[now] = dep[ff] + 1;
	if(dep[now] > 2){
		//≥¢ ‘º∆À„
		dis[1][1][now] = calc(now, ff, fa[ff], 1, 1);
		dis[1][2][now] = calc(now, ff, fa[ff], 1, 2);
		dis[2][1][now] = calc(now, ff, fa[ff], 2, 1);
		dis[2][2][now] = calc(now, ff, fa[ff], 2, 2);	
		ans += dis[1][min(2, ff - now)][now];
	}
	for(auto y: e[now]){
		dfs(y, now);
	}
} 
//ø®≥£Œ“∫ﬁƒ„ 
void work(){
	ICS++;
	n = read();
	d = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		e[i].clear();
		fa[i] = 0;
		dep[i] = 0;
		for(int j = 1; j <= 2; j++){
			for(int k = 1; k <= 2; k++){
				dis[j][k][i] = 0;
			}
		}
	}
	int j = 1;
	for(int i = 1; i <= n; i++){
		while(j + 1 <= n && a[j + 1] - a[i] <= d) j ++;
		fa[i] = j;
		if(fa[i] != i){
			e[fa[i]].push_back(i);
		} 
	}
	ans = 0;
	for(int i = n; i >= 1; i--){
		if(fa[i] == i){
			
			dfs(i, 0);
		}
	}
	cout << ans << '\n';
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read();
	int TCS = read();
	while(TCS --){
		work();
	}
	return 0;
}
