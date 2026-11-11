//15:12开T2
//坏了忘了priority怎么重载运算符了
//站厅、站台、地铁口，谢谢已经分不清了 
//显然离线
//可以画成一个只有两边的图
//说实话，太像dp了 
//d<=20有啥用 
//每条线路最多5e5个站，每个站最多20条线路
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+505,M=1e5+5;
int c,n,m,k[N],w[N],d,q;
//int a[505][N],t[505][N];
int x[M],y[M],dis[N];
struct node{
	int to,val;
};
vector<node>G[N];
struct tsy{//我也不知道这啥语法，但是能跑，话说为啥那个小于改成大于就不行了啊 
	int di;
	int val;
	bool operator < (const tsy&t) const{
		return this->val > t.val;
	} 
};
bool vis[N];
void dij(int st){
	memset(vis,0,sizeof vis);
	priority_queue<tsy>q;
	q.push((tsy){st,0});
	for(int i=1;i<=m;i++)dis[i]=1e15;
	dis[st]=0;
	while(q.size()){
		tsy arr=q.top();
		q.pop();
		if(vis[arr.di])continue;
		vis[arr.di]=1;
		for(int i=0;i<G[arr.di].size();i++){
			int v=G[arr.di][i].to,wl=G[arr.di][i].val;
			if(arr.val+wl<dis[v]){
				q.push((tsy){v,arr.val+wl});
				dis[v]=arr.val+wl;
			}
		}
	}
}
int wa[1005][1005];
void workA(){//性质A，可以简化为地铁站之间的图，然后地铁站之间的边可以化简，只留最短的，变成一个无向图
//无向图，1000个点，相互的最短距离
//做一次dijstra的复杂度为nlogn，n次就是n^2logn ，大概1e7
//但是我不记得怎么重载运算符了！ 
//手写堆嘛，还是
//ye打炸了 
//原来是没双向边
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int ta,tb,tc,td;
		if(k[i]==2){
			cin>>ta>>tb>>tc>>td;
			G[ta].push_back((node){tc,tb+td});
			G[tc].push_back((node){ta,tb+td});
		}
		else cin>>ta;
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=m;i++){
		dij(i);
		for(int j=1;j<=m;j++)wa[i][j]=wa[j][i]=dis[j];
	}
	for(int i=1;i<=q;i++)cout<<wa[x[i]][y[i]]+w[x[i]]+w[y[i]]<<'\n';
}

struct wry{
	int di;
	int val;
};

void bfs(int st,int ed){
	queue<wry>q;
	memset(vis,0,sizeof vis);
	q.push((wry){st,w[st]+w[ed]});
	while(q.size()){
		wry arr=q.front();
		q.pop();
		if(arr.di==ed){
			cout<<arr.val<<'\n';
			return;
		}
		if(vis[arr.di])continue;
		vis[arr.di]=1;
		for(int i=0;i<G[arr.di].size();i++){
			int v=G[arr.di][i].to,wl=G[arr.di][i].val;
			q.push((wry){v,arr.val+wl});
		}
	}
}

void workB(){//性质B应该就是一个bfs我寻思，然后把地铁站的编号加个m
//但很显然我只能拿到12到15这四个 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int arra,arrt;
			cin>>arra>>arrt;
			G[i+m].push_back((node){arra,arrt});
			G[arra].push_back((node){i+m,arrt});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		bfs(x[i],y[i]);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(7<=c&&c<=11){//性质A 
		workA();
	}
	else if(12<=c&&c<=19){
		workB();
	}
	return 0;
}
