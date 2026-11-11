#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		if(f) x=-x;return x;
	}
	template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		int cnt=0;char tmp[41];
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}
}
using namespace FastIO;
const int N=1e6+10,M=2e6+10,NN=5e2+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct chain_forward_star{int nxt,to,w;}edge[M<<1];
int head[N],W[N],k[N],t[N],cid,n,m,D,Q,cnt,ecnt;
vector<pair<int,int> >p[N];
ll Dis[NN][NN],dis[N];
bool vis[N];
struct node{
	int u;ll dis;
	inline bool operator>(const node&o) const{return dis>o.dis;}
};
priority_queue<node,vector<node>,greater<node> >q;
inline void add(int u,int v,int w){edge[++ecnt]={head[u],v,w},head[u]=ecnt;}
void dijkstra(int start){
	for(int i=1;i<=cnt;i++) dis[i]=INF,vis[i]=false;
	dis[start]=0,q.push({start,0});
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to,w=edge[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	read(cid),read(n),read(m),read(D),read(Q);
	for(int i=1;i<=m;i++) read(W[i]);
	for(int i=1;i<=n;i++){
		read(k[i]);
		for(int x,t;k[i]--;){
			read(x),read(t);
			p[x].emplace_back(make_pair(i,t));
			add(x+n,i,t),add(i,x+n,t);
		}
	}
	cnt=n+m;
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++) Dis[i][j]=dis[j];
	}
	for(int x,y;Q--;){
		read(x),read(y);
		ll ans=INF;
		for(pair<int,int>sonx:p[x]){
			for(pair<int,int>sony:p[y]){
				int t1=sonx.second,t2=sony.second;
				int st=sonx.first,ed=sony.first;
				ans=min(ans,Dis[st][ed]+t1+t2);
			}
		}
		write(ans+W[x]+W[y],'\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
