#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int m,n;
int c,d,pq;
struct side{
	long long v,w;
	bool operator>(const side&a)const{
		return w>a.w;
	}
};
vector<side>g[5000505];
priority_queue<side,vector<side>,greater<side> >q;
long long dis[2000005];
int w[2000005];
int km,mak;
void in(int s){
	for(int i=1;i<=mak;i++)dis[i]=0x7fffffffffffff;
	dis[s]=0;
	q.push({s,0});
}
void dij(){
	while(!q.empty()){
		int u=q.top().v;
		long long d=q.top().w;
		q.pop();
		if(d>dis[u])continue;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(dis[u]!=0x7fffffffffffff and dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>pq;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		km+=k;
		for(int j=1;j<=k;j++){
			long long v,w;
			cin>>v>>w;
			mak=max(v,(long long)mak+n);
			g[i].push_back({n+v,w});
			g[n+v].push_back({i,w});
		}
	}
	while(pq--){
		int s,e;
		cin>>s>>e;
		in(n+s);
		dij();
		cout<<w[s]+dis[n+e]+w[e]<<endl;
	}
	return 0; 
} 
