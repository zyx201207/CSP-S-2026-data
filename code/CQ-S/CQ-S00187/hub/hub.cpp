#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,k,dis[25],vis[25],fa[25];
int find(int u){return (fa[u]?fa[u]=find(fa[u]):u);}
vector<int> edge[2000005];
void solve(){
	for(int i=1;i<=n;i++)edge[i].clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if(n<=20){
		int ans=INT_MAX;
		for(int w=0;w<(1<<n);w++){
			if(__builtin_popcount(w)==k){
				memset(dis,0,sizeof(dis));
				memset(vis,0,sizeof(vis));
				memset(fa,0,sizeof(fa));
				queue<int> q;
				int ltk=k;
				for(int i=1;i<=n;i++)if(w&(1<<(i-1))){
					q.push(i);
					vis[i]=1;
					for(int j:edge[i])if(w&(1<<(j-1))){
						if(find(i)!=find(j))fa[find(i)]=find(j),ltk--;
					}
				}
				if(ltk>2)continue;
				while(q.size()){
					int u=q.front();
					q.pop();
					for(int i:edge[u]){
						if(!vis[i]){
							dis[i]=dis[u]+1;
							vis[i]=1;
							q.push(i);
						}
					}
				}
				int mx=0;
				for(int i=1;i<=n;i++)mx=max(mx,dis[i]),(vis[i]?void():exit(1143));
				ans=min(mx,ans);
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
这有什么最优化的方法吗？
感觉没有
考虑二分答案
然后就是放最少的关键点 
让里关键点最远的不超过mid
然后可以往上面放就往上面放
这是比较显然的
如果都可以把子树内的覆盖，那放的越高肯定越好
但是他放一个关键点可以覆盖一部分上面的

dp[i][j][k]表示子树内最深的未覆盖为j，最浅的关键点为k有点炸了

 
*/ 
