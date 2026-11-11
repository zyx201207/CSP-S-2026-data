#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while (!isdigit(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if (x < 0){
		putchar('-');
		write(-x);
		return ;
	}
	if (x < 10){
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}
int n,d;
int a[2000050];
signed nxt[2000050],pre[2000050],p2[2000050],n2[2000050];
vector <int> point;
int mp[2000050];
int f[550][550],g[550][550];
const int B = 500;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	c = read(),T = read();
	while (T--){
		for (int i = 1;i <= n;i++) nxt[i] = pre[i] = p2[i] = n2[i] = mp[i] = 0;
		point.clear();
		if (c <= 6) for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) f[i][j] = g[i][j] = 0;
		n = read(),d = read();
		for (int i = 1;i <= n;i++) a[i] = read();
		int j = 1;
		pre[1] = 0;
		for (int i = 2;i <= n;i++){
			while (a[i] - a[j] > d && j <= i) j++;
			pre[i] = j;
			n2[j] = i;
		}
		j = n;
		nxt[n] = n + 1;
		for (int i = n - 1;i >= 1;i--){
			while (a[j] - a[i] > d && j >= i) j--;
			nxt[i] = j;
			p2[j] = i;
		}
		if (c <= 6){
			memset(g,0x3f,sizeof(g));
			for (int i = 1;i <= n;i++){
				f[i][i] = 1,g[i][i] = 0;
				for (int j = i + 1;j <= nxt[i];j++){
					f[i][j] = 1;
					g[i][j] = 1;
				}
			}
			for (int len = 1;len <= n;len++){
				for (int i = 1;i + len - 1 <= n;i++){
					int j = i + len - 1;
					if (g[i][j] == 0 || g[i][j] == 1) continue;
					for (int k = i;k <= j;k++) g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
					for (int k = i + 1;k <= j - 1;k++) if (g[i][k] + g[k][j] == g[i][j]) f[i][j] += f[i][k] * f[k][j];
				}
			}
			int cnt = 0;
			for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) if (f[i][j] == 2) cnt++;
			write(cnt),putchar('\n');
			continue;
		}
		for (int i = 1;i <= n;i++) if (pre[nxt[i]] == i - 1) point.push_back(i);
		for (int i = 1;i <= n;i++) if (pre[nxt[i]] <= i - 1) mp[i] = 1;
		int ans = 0;
		for (int i = 0;i < point.size();i++){
			int u = point[i],v = nxt[point[i]];
			int cnt1 = 0,cnt2 = 1;
			int tmp = nxt[v];
			while (tmp <= n && !mp[tmp]) cnt2++,tmp = nxt[tmp];
			tmp = p2[u];
			while (tmp >= 1 && !mp[tmp]) cnt1++,tmp = p2[tmp];
			if (mp[tmp]) cnt2++;
			ans += cnt1 * cnt2;
		}
		for (int i = 1;i <= n;i++){
			int u = i,v = nxt[i];
			if (v >= n) continue;
			int w = n2[v - 1];
			if (w >= n || w == 0) continue;
			int cnt = 1;
			int tmp = w;
			while (tmp >= 1 && !mp[tmp]) cnt++,tmp = p2[tmp];
			ans += cnt;
		}
		write(ans),putchar('\n');
	}
	return 0;
}