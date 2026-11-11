#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c = getchar();
	int x = 0,neg = 1;
	while(c < '0' || c > '9'){
		if(c == '-') neg = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x*10 + c - '0';
		c = getchar();
	}
	return x * neg;
}
#define PII pair<int,int>
const int N = 2e6 + 10;
int c,t,n,dis[N],vis[N],cnt[N],ans = 0;
long long d,x[N];
vector<int> e[N];
int bfs(int st,int ed){
	for(int i = 1;i <= n;i++) dis[i] = 0x3f3f3f3f;
	for(int i = 1;i <= n;i++) vis[i] = 0,cnt[i] = 0;
	dis[st] = 0;
	priority_queue< PII,vector<PII>,greater<PII> > q;
	q.push(make_pair(0,st));
	while(!q.empty()){
		if(cnt[ed] > 2) break;
		int u = q.top().second,cost = q.top().first;
		q.pop();
		if(vis[u]){
			if(cost == dis[u]) cnt[u]++;
			continue;
		}
		vis[u] = 1;
		cnt[u] = 1;
		for(auto v : e[u]){
			if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1;
			if(v <= ed) q.push(make_pair(dis[u]+1,v));
		}
	}
	if(cnt[ed] == 2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		ans = 0;
		for(int i = 1;i <= n;i++) e[i].clear();
		for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);
		sort(x+1,x+1+n);
		for(int i = 1;i <= n;i++)
			for(int j = i+1;j <= n;j++)
				if(x[j] - x[i] <= d)
					e[i].push_back(j);
		
		for(int i = 1;i <= n;i++)
			for(int j = i+1;j <= n;j++)
				ans += bfs(i,j);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2 
6 2
-4 -3 -2 -1 3 6

*/
