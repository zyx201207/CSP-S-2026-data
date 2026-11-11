// 打一个15分的暴力吧、 

#include <bits/stdc++.h>
using namespace std;

const int N=50;

int n, k;
vector<int> e[N];

int s;

bool vis[N];

void dfs1(int x, int f){
	if (!(s&(1<<x)))	return ;
	vis[x]=1;
	for (int y: e[x]){
		if (y==f)	continue;
		dfs1(y, x);
	}
}

int dfs(int x, int f){
	if (s&(1<<x))	return 0;
	int res=999999999;
	for (int y: e[x]){
		if (y==f)	continue;
		res=min(res, dfs(y, x)+1);
	}
	return res;
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int C, T;
	scanf("%d%d", &C, &T);
	while (T--){
		scanf("%d%d", &n, &k);
		for (int i=1; i<n; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		
		int ans=999999999;
		for (s=0; s<(1<<(n+1)); s+=2){
			int popcnt=0;
			for (int j=1; j<=n; j++)
				if (s&(1<<j))
					popcnt++;
			if (popcnt!=k)	continue;
			
			int cnt=0;
			memset(vis, 0, sizeof vis);
			for (int i=1; i<=n; i++){
				if (s&(1<<i) && !vis[i]){
					dfs1(i, 0);
					cnt++;
				}
			}
			if (cnt>2)	continue;
			
			int res=0;
			for (int i=1; i<=n; i++)	res=max(res, dfs(i, 0));
			ans=min(ans, res);
		}
		
		printf("%d\n", ans);
		
		for (int i=1; i<=n; i++)	e[i].clear();
	}
	return 0;
}
