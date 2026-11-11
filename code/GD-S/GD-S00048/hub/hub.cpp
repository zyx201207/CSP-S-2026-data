#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,k,u,v,vis[N],pd[N],dist[N],ans=1e18;
vector<int> edge[N];
void sovle(int x){
	pd[x]=1;
	for(auto tx:edge[x]){
		if(pd[tx])continue;
		if(!vis[tx])continue;
		sovle(tx);
	}
}
void getmin(int x,int fa){
	for(auto tx:edge[x]){
		if(tx==fa)continue;
		getmin(tx,x);
		dist[x]=min(dist[x],dist[tx]+1);
	}
}
void dfs(int x,int cs){
	if(cs>k)return;
	if(x==n){
		if(cs!=k)return;
		int cnt=0,tmp=0;
		for(int i=1;i<=n;i++)pd[i]=0;
		//cnt表示形成的连通块数量 
		for(int i=1;i<=n;i++){
			if(vis[i]&&pd[i]==0){
				cnt++;
				sovle(i);
			}
		}
		if(cnt>2)return;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dist[j]=1e18;
			for(int j=1;j<=n;j++)if(vis[j])dist[j]=0;
			getmin(i,0),tmp=max(tmp,dist[i]);
		}
		ans=min(ans,tmp);
		return;
	} 
	vis[x+1]=1;
	dfs(x+1,cs+1);
	vis[x+1]=0;
	dfs(x+1,cs);
}
void sovle(){
	cin>>n>>k;
	ans=1e18;
	for(int i=1;i<=n;i++)edge[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0,0);
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)sovle();
	return 0;
}
//目前会15分
//二等大概率保住了，接下来冲一等！！！ 
//现在想k=2 
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
//15分？
//估分100+44+24+15=178 
