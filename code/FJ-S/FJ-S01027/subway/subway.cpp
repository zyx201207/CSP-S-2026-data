#include<bits/stdc++.h>
using namespace std;
const int N = 600, M = 300, Q = 1e5 + 10;
int c,n,m,d,q;
int w[M],k[N],x[Q],y[Q],ans[Q]= {0};
int a[N][N],t[N][N];
bool isline (int p1, int p2) {
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= sizeof(a[i]); j++) {
			if (p1 == a[i][j] || p2 == a[i][j]) {
				cnt++;
			}
			if (cnt == 2) {
				ok = true;
				break;
			}
		}
	}	
	return ok;
}		
int haveline(int p) {
	int num = 0;
	for (int i =1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == p) {
				num++;
			}
		}
	}	
	return num;
}		
int goline(int sta, int end, int l) {
	int res = 0;
	for (int i = sta; i <= end; i++) {
		res += t[l][i];
	}	
	res += w[end];
	return res;
}		
int findline (int p1, int p2) {
	int line = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= sizeof(a[i]); j++) {
			if (p1 == a[i][j] || p2 == a[i][j]) {
				cnt++;
			}
			if (cnt == 2) {
				if (goline(p1,p2,i) < goline(p1,p2,line)) line = i;
				break;
			}
		}
	}	
	return line;
}		
void bfs(int cur, int end, int op) {
	int res = 0;
	if (cur == end) return;
	for (int i = 1; i <= haveline(cur); i++) {
		for (int j = 1; j <= n; j++) {
			if (isline(a[i][cur],a[i][cur+1]) && isline(a[i][cur+1],a[j][end])) {
				res += goline(a[i][cur],a[i][cur+1],i) + goline(a[i][cur+1],a[j][end],j);
				bfs(cur+1,end,op);
			}
		}
	}	
	ans[op] = min(ans[op],res);
}		
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}	
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}	
	for (int r = 1; r <= q; r++) {
		cin >> x[r] >> y[r];
	}	
	for (int i = 1; i <= q; i++) {
		ans[i] += w[x[i]];
		if (isline(x[i],y[i])) {
			int l = findline(x[i],y[i]);
			ans[i] += goline(x[i],y[i],l);
			continue;
		} else {
			int cur = x[i];
			bfs(cur,y[i],i);
		}
	}	
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << endl; 
	}	
	return 0;
}		
