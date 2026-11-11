#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int input();
void print(int x);
int x[5001],dis[5001][5001],ans,sum;
bool vis[5001];
vector <vector <int>> edge;
void dfs(int u,int v,int i,int d){
	if (i==v){
		if (d==dis[u][v]) ++sum;
		return;
	}
	if (vis[i]) return;
	vis[i]=1;
	for (int j:edge[i]) dfs(u,v,j,d+1);
	vis[i]=0;
}
inline void bfs(int s){
	memset(vis,0,sizeof vis);
	queue <pair <int,int>> q;
	q.push({s,0});
	vis[s]=1;
	while (!q.empty()){
		int u=q.front().first,d=q.front().second;
		q.pop();
		dis[s][u]=dis[u][s]=d;
		for (int v:edge[u]){
			if (!vis[v]){
				q.push({v,d+1});
				vis[v]=1;
			}
		}
	}
}
inline void solve(){
	edge.clear();
	int n=input(),d=input();
	edge.resize(n+1);
	ans=0;
	for (int i = 1;i<=n;i++){
		x[i]=input();
		for (int j = 1;j<i;j++){
			if (abs(x[i]-x[j])<=d){
				edge[i].push_back(j);
				edge[j].push_back(i);
			}
		}
	}
	for (int i = 1;i<=n;i++) bfs(i);
	for (int i = 1;i<=n;i++){
		for (int j = i+1;j<=n;j++){
			memset(vis,0,sizeof vis);
			sum=0;
			dfs(i,j,i,0);
			if (sum==2) ++ans;
		}
	}
	print(ans),puts("");
}
signed main(void){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=input(),t=input();
	while (t--) solve();
	return 0;
}
inline int input(){
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
