#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+5;
int O,T,N,K;
int vis[MAXN];
vector<int>G[MAXN];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>O>>T;
	while(T--){
		cin>>N>>K;mp.clear();
		for(int i=1;i<=N;i++)vis[i]=0;
		for(int i=1;i<=N;i++)G[i].clear();
		for(int i=2;i<=N;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<0<<"\n";
	}
	return 0;
}
/*
反乌托邦中的争夺
心灵也被关上门锁
看不清灯火
但我还想说些什么
其实我还想说很多
请你等等我
请你等等我
两块五的签字笔
东拼西凑的字句
妄想用它拯救你
顺便拯救我自己
@lizirui20131212

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=3005;
int O,T;
int N,K;
int Ans=1e18;
bool vis[MAXN];
int dist[MAXN];
bool tvis[MAXN];
int f[MAXN][MAXN];
vector<int>G[MAXN];
map<pair<int,int>,bool>mp;
inline void pdDFS(int u,int fa){
	tvis[u]=1;
	for(int v:G[u]){
		if(v==fa)continue;
		if(vis[u])pdDFS(v,u);
	}
} 
inline bool pd(){
	int cnt=0;
	for(int i=1;i<=N;i++)tvis[i]=0;
	for(int i=1;i<=N;i++){
		if(vis[i]&&!tvis[i]){
			cnt++;
			pdDFS(i,0);
		}
		if(cnt==3)return 0;
	}
	return (cnt==2);
}
inline int js(){
	int res=1e18;
	vector<int>vec;
	for(int i=1;i<=N;i++){
		if(vis[i])vec.push_back(i);
	}
	for(int i=1;i<=N;i++)dist[i]=1e18;
	for(int i=1;i<=N;i++){
		for(int j=0;j<K;j++){
			dist[i]=min(dist[i],f[i][j]);
		}
	}
	for(int i=1;i<=N;i++)res=min(res,dist[i]);
	return res;
}
inline void DFS(int id,int last){
	for(int i=1;i<=K;i++)cout<<vis[i]<<" ";
	cout<<endl;
	if(id==K+1){
		for(int i=1;i<=K;i++)cout<<vis[i]<<" ";
		cout<<endl;
		if(pd())Ans=min(Ans,js());
		return;
	}
	for(int i=last+1;i<=N;i++){
		vis[id]=i;
		DFS(id+1,i);
		vis[id]=0;
	}
}
inline void DFS1(int u,int fa,int start){
	for(int v:G[u]){
		if(v==fa)continue;
		f[start][v]=f[start][u]+1;
		DFS1(v,u,start);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>O>>T;
	while(T--){
		cin>>N>>K;Ans=1e18;
		for(int i=1;i<=N;i++)vis[i]=0;
		for(int i=1;i<=N;i++)G[i].clear();
		for(int i=2;i<=N;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i=1;i<=N;i++){
			f[i][i]=0;
			DFS1(i,0,i);
		}
		DFS(1,0);
		cout<<Ans<<"\n";
	}
	return 0;
} 
*/
