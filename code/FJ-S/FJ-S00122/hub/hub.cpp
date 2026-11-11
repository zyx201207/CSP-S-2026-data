#include <bits/stdc++.h>
using namespace std;

int c, t;
int n, K;
vector<int> vec[12];
int dis[12], d[12];
int flag[12];
bool yes[12];
void dfs(int pos,int id){
	if(!yes[pos]) return;
	if(flag[pos] != 0) return;
	flag[pos] = id;
	for(int i=0;i<vec[pos].size();i++){
		dfs(vec[pos][i], id);
	}
}
queue<int> q;

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	
	while(t--){
		scanf("%d%d",&n,&K);
		for(int i=1;i<=n;i++){
			while(vec[i].size()) vec[i].pop_back();
		}
		for(int i=1;i<n;i++){
			int u, v;
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		int Ans = 1e9;
		for(int S=0;S<(1<<n);S++){
			int cnt = 0;
			for(int i=1;i<=n;i++) d[i] = 1e9;
			for(int i=1;i<=n;i++) flag[i] = 0, yes[i] = 0;
			for(int i=1;i<=n;i++) if((S >> (i-1)) & 1) yes[i] = 1;
			for(int i=1;i<=n;i++){
				if((S >> (i-1)) & 1) {
					cnt++;
					dfs(i, i);
					for(int j=1;j<=n;j++) dis[j] = 1e9;
					dis[i] = 0;
					q.push(i);
					while(!q.empty()){
						int u = q.front();
						q.pop();
						//if(flag[u] == 0) flag[u] = i;
						for(int o=0;o<vec[u].size();o++){
							int v = vec[u][o];
							if(dis[v] == 1e9){
								dis[v] = dis[u] + 1;
								q.push(v);
							}
						}
					}
					for(int j=1;j<=n;j++) {
						d[j] = min(d[j], dis[j]);
					}
				}
			}
			int x = -1, x2 = -1;
			bool fail = 0;
			for(int i=1;i<=n;i++){
				if(flag[i] != 0){
					if(x == -1) x = flag[i];
					else if(flag[i] != x) {
						if(x2 == -1) x2 = flag[i];
						else if(flag[i] != x2) fail = 1;
					}
				}
			}
			if(fail) continue;
			if(cnt != K) continue;
			int ans = 0;
			for(int i=1;i<=n;i++) ans = max(ans, d[i]);
			Ans = min(Ans, ans);
		}
		printf("%d\n",Ans);
	}
	
	
	return 0;
}

/*

0 1
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
