#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define MAXN (int(2e5+5))
int n, m, a[MAXN], cnt[MAXN], b[MAXN][35];
bool vis[MAXN];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		int x = a[i], tot = 0;
		while(x) {
			cnt[++tot] += x & 1;
			b[i][tot] = x & 1;
			x >>= 1;
		}
	}
	for(int i = 1; i + m <= n; i++) {
		int minx = 1007483647, minb = 0;
		for(int j = 1; j <= n; j++) {
			if(vis[j]) break;
			int tt = 0;
			for(int k = 1; k <= 31; k++) {
				if(b[j][k] == 1 && cnt[k] == 2)  {
					tt += (1<<(k-1));
				}
			}
			if(minx > tt) minx = tt, minb = j;
		}
		for(int k = 1; k <= 31; k++) {
			if(b[minb][k])
				cnt[k]--;
		}
		vis[minb] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= 31; i++) {
		ans += (1<<(i-1)) * (cnt[i] >= 2);
	}
	cout<<ans;
	return 0;
}

/*
5 3
31 3 1 15 7

*/