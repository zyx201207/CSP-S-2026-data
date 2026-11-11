#include<bits/stdc++.h>
using namespace std;

int c, T, n, k;
vector<int> edge[1000005];
bool sxs[1000005];

inline int ask(int p, int f){
	if(sxs[p]) return 0;
	int fh = 1e9;
	for(int v : edge[p]){
		if(v == f) continue;
		fh = min(fh, ask(v, p) + 1);
	}
	return fh;
}

inline int sltk(int u, int f, int jq){
	int sum = jq;
	if(sxs[u]) sum++;
	for(int v : edge[u]){
		if(v == f) continue;
		if(sxs[u] && sxs[v]) sum += sltk(v, u, -1);
		else sum += sltk(v, u, 0);
	}
	return sum;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	if(c == 13 || c == 14){
		while(T--){
			scanf("%d%d", &n, &k);
			for(int i = 1; i <= n; i++) edge[i].clear();
			for(int i = 1; i < n; i++){
				int u, v;
				scanf("%d%d", &u, &v);
				edge[u].push_back(v);
				edge[v].push_back(u);
			}
			if(k == n){
				printf("0\n");
				continue;
			}
			if(k >= n / 2){
				printf("1\n");
				continue;
			}
			int l = 1, r = n, ans;
			while(l <= r){
				int mid = l + r >> 1;
				int ll = mid, rr = n / 2 + 1 - mid;
				if(rr - ll + 1 <= k || ((rr - ll) - (k - 2)) / 2 + 1 <= mid) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			printf("%d\n", ans);
		}
		return 0;
	}
	while(T--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) edge[i].clear();
		for(int i = 1; i < n; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int ans = 1e9;
		for(int i = 0; i < (1 << n); i++){
			if(__builtin_popcount(i) != k) continue;
			for(int j = 1; j <= n; j++) sxs[j] = 0;
			for(int j = 1; j <= n; j++){
				if((i & (1 << j - 1))) sxs[j] = 1;
			}
			//printf("%d %d\n", i, sltk(1, 0, 0));
			if(sltk(1, 0, 0) > 2) continue;
			int sum = 0;
			for(int j = 1; j <= n; j++) sum = max(ask(j, 0), sum);
			ans = min(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}
