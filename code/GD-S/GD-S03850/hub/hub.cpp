#include<iostream>
#include<vector>
#include<queue>
#define int long long 
using namespace std;
int n,m,ccid,t,cnt;
int s[1000005],rk[1000005],ans;
bool vis[1000005];
vector<int>g[1000005];
int find_set(int x){
	if(x==s[x])return x;
	return s[x] = find_set(s[x]);
}
void merge_set(int u,int v){
	u = find_set(u);v = find_set(v);
	if(u==v)return;
	if(rk[u]<rk[v])swap(u,v);
	if(rk[u]==rk[v])++rk[u];
	s[v] = u;
	--cnt;
}
struct eg{
	int u,v;
}e[1000005];
struct str{
	int u,dis;
};
queue<str>q;
int popcnt(int x){
	int res = 0;
	while(x){
		res++;
		x -= x&-x; 
	}
	return res;
}
void solve(int mask){
	int maxdis = 0;
	cnt = popcnt(mask);
	if(cnt!=m)return;
	for(int i =1;i<=n;i++)s[i] = i;
	for(int i =1;i<n;i++){
		int u = e[i].u,v = e[i].v;
		if((mask&(1<<u-1))&&(mask&(1<<v-1))){
			merge_set(u,v);
		}
	}
	if(cnt>2)return;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=n;j++)vis[j] = 0;
		int minx = 1e18;
		while(q.size())q.pop();
		q.push({i,0});
		vis[i] = 1;
		while(q.size()){
			int u = q.front().u,ds = q.front().dis;q.pop();
			if(mask&(1<<u-1)){
				maxdis = max(maxdis,ds);break;
			}
			for(int v:g[u]){
				if(vis[v])continue;
				q.push({v,ds+1});
				vis[v] = 1;
			}
		}
	}
	ans = min(ans,maxdis);
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>ccid>>t;
	while(t--){
		ans = 1e18;
		cin>>n>>m;
		for(int i =1;i<=n;i++)g[i].clear();
		for(int i =1;i<n;i++){
			cin>>e[i].u>>e[i].v;
			g[e[i].u].push_back(e[i].v);
			g[e[i].v].push_back(e[i].u);
		}
		for(int i =0;i<(1<<n);i++){
			solve(i);
		}
		cout<<ans<<"\n";
	} 
	
} 
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/
