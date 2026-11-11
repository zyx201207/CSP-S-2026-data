#include<bits/stdc++.h>
using namespace std;
const int N = 305;
long long x[N];
struct Edge{
	int v;
	long long dis;

}; 
vector<Edge> edges[N];
bool vis[N];

int startId, endId;
int cnt;
long long Dis;
long long minDis = INT_MAX;

void init(){
	minDis = INT_MAX;
	cnt = 0;
	memset(vis, false, sizeof(vis));
	Dis = 0;
	cnt = 0;
}

void dfs1(int now, int depth){
	if(depth > abs(startId - endId)){
		return;
	}
	if(now == endId){
		minDis = min(minDis, Dis); 
		return;
	}
	
	for(int i = 0; i < edges[now].size(); i++){
		if(!vis[edges[now][i].v]){
			vis[edges[now][i].v] = true;
			Dis++;
			dfs1(edges[now][i].v, depth + 1);
			vis[edges[now][i].v] = false;
			Dis--;
		}
	}
	return;
}

void dfs2(int now, int depth){
	if(depth > abs(startId - endId)){
		return;
	}
	if(now == endId){
		//cout << "Dis = " << Dis << "\n"; 
		if(Dis == minDis){
			cnt++;
			//cout << cnt << "\n";
		}
		return;
	}
	
	for(int i = 0; i < edges[now].size(); i++){
		if(!vis[edges[now][i].v]){
			vis[edges[now][i].v] = true;
			Dis++; 
			dfs2(edges[now][i].v, depth + 1);
			vis[edges[now][i].v] = false;
			Dis--;
		}
	}
	return;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, _T;
	scanf("%d%d", &c, &_T);
	while(_T--){
		int n;
		long long d;
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(abs(x[i] - x[j]) <= d){
					Edge e;
					e.v = j, e.dis = abs(x[i] - x[j]);
					edges[i].push_back(e);
					e.v = i;
					edges[j].push_back(e);
				}
			}
		}
		init();
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				init();
				startId = i, endId = j;
				dfs1(startId, 0);
				
				dfs2(startId, 0); 
				//cout << minDis << "\n";
				if(cnt == 2){
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
