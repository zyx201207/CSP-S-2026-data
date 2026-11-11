#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace IO{
	template<typename T>void read(T &x){short f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();x*=f;return;}
	template<typename T>void out_(T x){if(x>9) out_(x/10);putchar(x%10+'0');return;}
	template<typename T>void out(T x){if(x<0) putchar('-'),x=-x;out_(x),putchar(' ');return;}
	void endl(){putchar('\n');return;}
}using namespace IO;
char st;
const int N=5e5+5,inf=9e18;
struct node{int id,dis;};
bool operator <(node a,node b){return a.dis>b.dis;}
int Tid,n,m,d,q,w[N],num[N],siz[N],dis[505][505],bz[N]; 
pair<int,int>stop[N][21]; //first 为线路 second 为路程 
vector<pair<int,int>>e[N]; //first 为点，second 为路程 
char ed;
void dij(int x){
	for(int i=1;i<=n;i++) dis[x][i]=inf,bz[i]=0;
	dis[x][x]=0;
	priority_queue<node>p;
	p.push((node){x,dis[x][x]});
	while(!p.empty()){
		node now=p.top();
		p.pop();
		int pos=now.id;
		if(bz[pos]) continue;
		bz[pos]=1;
		for(pair<int,int>g:e[pos]){
			int u=g.first,z=g.second;
			if(dis[x][u]>dis[x][pos]+z){
				dis[x][u]=dis[x][pos]+z;
				p.push((node){u,dis[x][u]});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cerr<<"Memory:"<<(&st-&ed)/1048576.0<<"MB"<<endl;
	read(Tid),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;i++) read(w[i]);
	for(int i=1;i<=n;i++){
		read(siz[i]);
		for(int j=1;j<=siz[i];j++){
			int x,y;
			read(x),read(y);
			++num[x];
			stop[x][num[x]]=make_pair(i,y);
		}
	}
	for(int i=1;i<=m;i++){ //预处理线路与线路 
		for(int j=1;j<=num[i];j++){
			for(int k=j+1;k<=num[i];k++){
				int x=stop[i][j].first;
				int y=stop[i][k].first;
				int z=stop[i][j].second+stop[i][k].second;
				e[x].push_back(make_pair(y,z));
				e[y].push_back(make_pair(x,z));
			}
		}
	}
	//跑最短路
	for(int i=1;i<=n;i++) dij(i);
	//debug
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dis[i][j]==inf) out(-1);
//			else out(dis[i][j]);
//		}
//		endl();
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		read(x),read(y);
		//直接枚举从哪个站台走
		int ans=inf;
		for(int j=1;j<=num[x];j++){
			for(int k=1;k<=num[y];k++){
				ans=min(ans,w[x]+w[y]+stop[x][j].second+stop[y][k].second+dis[stop[x][j].first][stop[y][k].first]);
			}
		} 
		out_(ans),endl();
	}
	return 0;
}

//start: 14:57

//accept thinking:15:03 考虑对 d 入手跑 dij ，建图缩点，预处理 。

//预计：15:40 

//提前 15:27 分过完大样例，感觉 舒服多了 
