#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2 * 1e6 + 5,inf = 1e18;
int c,t,n,d,x[maxn];

int g[305][305],lst[305];
void solve1() {
	memset(g,0,sizeof(g));
	memset(lst,0,sizeof(lst));
	
	cin >> n >> d;
	
	int l = 1;
	for(int i = 1;i <= n;i ++) {
		cin >> x[i];
		if(i == 1) {
			lst[i] = 0;
			continue;
		}
		while(x[i] - x[l] > d) {
			l ++;
		}
		lst[i] = l;
	}

	for(int i = 1;i <= n;i ++) {
		for(int j = 0;j + i <= n;j ++) {
			int a = j + 1,b = i + j;
			int x = b,cnt = 0;
			while(x > a) {
				x = lst[x];
				if(lst[x] == x) {
					cnt = inf;
					break;
				}
				cnt ++;
			}
			g[a][b] = cnt;
		}
	}
	
//	for(int i = 1;i <= n;i ++) {
//		for(int j = 1;j <= n;j ++) {
//			cout << g[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	
	int ans = 0;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j < lst[i];j ++) {
			int ming = g[j][i],cnt = 0;
			
			for(int k = lst[i];k < i;k ++) {
				if(g[j][k] + g[k][i] == ming) {
					cnt ++;
				}
			}
			if(cnt == 2) {
				ans ++;
			}
		}
	}
	
	cout << ans << '\n';
	
	return;
}


signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> c >> t;
	while(t --) {
		solve1();
	}
	
	return 0;
}


