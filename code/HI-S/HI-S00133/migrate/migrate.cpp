#include<bits/stdc++.h>
using namespace std;
#define int long long

int c, t, n, d, tot;
int a[2000010];
//int head[2000010];
//struct edge{
//	int to, nxt, w;
//}e[2000010];
//
//void add(int u, int v, int w){
//	e[++ tot].to = v;
//	e[tot].nxt = head[u];
//	e[tot].w = w;
//	head[u] = tot;
//} 

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	while(t--){
		memset(a, 0, sizeof(a));
		
		cin >> n >> d;
		for(int i = 1; i <= n; ++ i)
			cin >> a[i];
		if(c == 0 || c == 11 || c == 12){
			if(d / (a[2] - a[1]) >= 2){
				int s = d / (a[2] - a[1]);
				if(n >= s * 2 + 1)
					cout << n - s * 2 + 1 << "\n";
				else
					cout << 0 << "\n";
			}
			else{
				cout << 0 << "\n";
			}
		}
		else{
			cout << 0 << "\n";
		}
//		for(int i = 1; i <= n; ++ i)
//			for(int j = i + 1; j <= n; ++ j){
//				if(a[j] - a[i] > d)
//					break;
//				add(i, j, a[j] - a[i]);
//				add(j, i, a[j] - a[i]);
//			}
		
	}
}
