#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int c,n,m,d,q,cnt;
priority_queue<pair<int,int> >qt;
bool vis[2005];
int dis[2005];
struct graph{
	int tot,head[2005],to[4005],nxt[4005],p[4005];
	inline void link(int a,int b,int c){
		nxt[++tot]=head[a];
		head[a]=tot;
		to[tot]=b,p[tot]=c;
	}
}T;
inline int Dij(int s,int e){
	for(int i=1;i<=cnt;i++) vis[i]=0,dis[i]=1e15;
	dis[s]=0;
	while(!qt.empty()) qt.pop();
	qt.push({0ll,s});
	while(!qt.empty()){
		int x=qt.top().second;
		qt.pop();
		if(x==e) return dis[e];
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=T.head[x];i;i=T.nxt[i]){
			int v=T.to[i],p=T.p[i];
			if(dis[v]>dis[x]+p){
				dis[v]=dis[x]+p;
				qt.push({-dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,a;i<=m;i++){//1~m 入口，m+1~2m 站厅 
		cin>>a;
		T.link(i,i+m,a);
		T.link(i+m,i,a); 
	}
	cnt=2*m;
	while(n--){
		int k;
		cin>>k;
		for(int i=1,a,b;i<=k;i++){
			cin>>a>>b;
			//站厅与站台的边 
			cnt++;
			T.link(a+m,cnt,b);
			T.link(cnt,a+m,b);
			//站台与站台的边
			if(i>1){
				T.link(cnt,cnt-1,0);
				T.link(cnt-1,cnt,0);
			} 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<Dij(x,y)<<'\n';
	}
	return 0;
} 
