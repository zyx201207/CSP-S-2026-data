#include<bits/stdc++.h>
using namespace std;
int n,k,ans=1e9,x=0;
bool ch[20];
bool visit[20];
vector<int>G[20];
void ltk(int root){
	for(int i=0;i<int(G[root].size());i++){
		if(visit[G[root][i]])continue;
		if(ch[G[root][i]]==0)continue;
		visit[G[root][i]]=1;
		ltk(G[root][i]);
	}
}
int solve(int root,int fa,int dist){
	int a=0x3f;
	for(int i=0;i<int(G[root].size());i++){
		if(G[root][i]==fa)continue;
		if(ch[G[root][i]])return dist+1;
		a=min(a,solve(G[root][i],root,dist+1));
	}
	return a;
}
void dfs(int now){
	if(now>n){
		memset(visit,0,sizeof(visit));
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!visit[i]&&ch[i])visit[i]=1,ltk(i),cnt++;
			if(cnt>2)return;
		}
		x=0;
		for(int i=1;i<=n;i++)if(ch[i])x=max(x,solve(i,-1,0));
		ans=min(ans,x);
		return;
	}
	ch[now]=1;
	dfs(now+1);
	ch[now]=0;
	dfs(now+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);G[v].push_back(u);
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
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
