#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> w[500505];
int sw[500005];
vector<int> v[500505];
long long dis[500505];
struct cmp{
	bool operator()(int a, int b){
		return dis[a] > dis[b];
	}
};
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", sw+i);
	}
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++){
			int a, t;
			scanf("%d%d", &a, &t);
			v[m + i].push_back(a);
			v[a].push_back(m + i);
			w[m + i].push_back(t);
			w[a].push_back(t);
		}
	}
	////
//	for(int i = 1; i <= n + m; i++){
//		printf("%d: ", i);
//		for(int j = 0; j < v[i].size(); j++){
//			printf("%d, ", v[i][j]);
//		}
//		printf("\n");
//	}
	////
	for(int i = 1; i <= q; i++){
		int sta, tar;
		scanf("%d%d", &sta, &tar);
		bool vis[500505];
		memset(vis, false, sizeof(vis));
		for(int i = 1; i <= m + n; i++){
			dis[i] = LONG_LONG_MAX;
		}
		dis[sta] = 0;
		priority_queue<int, vector<int>, cmp> ps;
		ps.push(sta);
		for(int k = 1; k < m + n; k++){
			int p = ps.top();
			ps.pop();
			if(p == tar)	break;
			vis[p] = true;
			for(int j = 0; j < v[p].size(); j++){
				if(vis[v[p][j]]){
					continue;
				}
				dis[v[p][j]] = min(dis[v[p][j]], dis[p] + w[p][j]);
				ps.push(v[p][j]);
			}
		}
//		printf("%d, %d, %lld\n", sta, tar, dis[tar]);
		printf("%lld\n", sw[sta] + dis[tar] + sw[tar]);
	}
	return 0;
}

