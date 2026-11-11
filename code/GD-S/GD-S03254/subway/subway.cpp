#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
int c,n,m,d,q,ans;
int Start[N],End[N],w[N],k[N],t[31][510];
vector<int> station[N],road[510],g[N];
//测试点编号、地铁线路数、地铁站数
//每个地铁站最多被几条线路经过，以及出行计划数
bool vis[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9' || ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void init(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(register int j=1;j<=k[i];j++){
			int id=read();
			road[i].push_back(id);
			//第i条线路所能到达的地铁站 
			station[id].push_back(i);
			//该地铁站能做的线路编号
			//id地铁站编号 i地铁线路编号 
			t[id][i]=read();
		}
	}
	for(register int i=1;i<=q;i++){
		Start[i]=read();
		End[i]=read();
	}
	return;
}
void bfs(int from,int to,int cnt){
	if(vis[from] || cnt>=ans) return;
	if(from==to){
		ans=min(ans,cnt);
		return;
	}
	for(register auto i:station[from]){
		for(register auto v:road[i]){
			vis[from]=true;
			bfs(v,to,cnt+t[from][i]+t[v][i]);
			vis[from]=false;
		}
	}
	return;
}
void solve(int p){
	int u=Start[p],v=End[p];
	ans=1e9;
	bfs(u,v,w[u]+w[v]);
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	for(int i=1;i<=q;i++)
		solve(i);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
