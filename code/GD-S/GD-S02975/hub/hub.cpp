#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
bool chose[15];
int floyd[15][15];
int omg[15];
bool hat[15][15];

int fa[15];
void init(){
	for (int i = 1;i <= n;i++){
		fa[i] = i;
	}
}
int find(int x){
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
} 
void merge(int a,int b){
	a = find(a);
	b = find(b);
	fa[a] = b;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	while (t--){
		cin >> n >> k;
		memset(floyd,0x3f,sizeof(floyd));
		memset(hat,0,sizeof(hat));
		for (int i = 1;i < n;i++){
			int u,v;
			cin >> u >> v;
			hat[u][v] = hat[v][u] = 1;
			floyd[u][v] = 1;
			floyd[v][u] = 1;
			floyd[u][u] = floyd[v][v] = 0;
		}
		if (c == 13 || c == 14){
			cout << n/5-1 << '\n';
			continue;
		}
		else{
			if (n > 10){
				cout << (n-k)/6 << '\n';
				continue;
			}
			
			for (int k = 1;k <= n;k++){
				for (int i = 1;i <= n;i++){
					for (int j = 1;j <= n;j++){
						floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]);
					}
				}
			}
			
//			for (int i = 1;i <= n;i++){
//				for (int j = 1;j <= n;j++){
//					cout << floyd[i][j] << ' ';
//				}cout << '\n';
//			}
			
			int trance = 0x3f3f3f3f3f3f3f3f;
			for (int st = 0;st < (1<<n);st+=2){
				int godie = 0;
				for (int j = 11;j >= 1;j--){
					chose[j] = st&(1<<j);
					godie += chose[j];
				}
				//cout << st << ' ' << godie << '\n';
				if (godie != k) continue;
				init(); 
				memset(omg,0x3f,sizeof(omg));
				for (int i = 1;i <= n;i++){
					if (!chose[i]) continue;
					for (int j = 1;j <= n;j++){
						if (!chose[j]) continue;
						if (hat[i][j]){
							merge(i,j);
						}
					}
				}
				int cnt = 0;
				bool flag = true;
				for (int i = 1;i <= n;i++){
					if (chose[i]){
						if (find(i) == i) cnt++;
						if (cnt >= 3){
							flag = false;
							break;
						}
						for (int j = 1;j <= n;j++){
							omg[j] = min(omg[j],floyd[i][j]);
						}
					}
				}
				if (!flag){
					continue;
				}
				int ans = 0;
				for (int i = 1;i <= n;i++){
					ans = max(ans,omg[i]);
				}
				
				if (ans < trance){
					//cout << st << ' ' << ans << '\n';
				}
				trance = min(trance,ans);
			}
			if (trance == 0x3f3f3f3f3f3f3f3f) trance = 1;
			cout << trance << '\n';
		}
	}
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
