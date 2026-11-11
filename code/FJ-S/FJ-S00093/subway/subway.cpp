#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,M=5e5+10,inf=1e18;
ll c,n,m,d,Q,w[M],dis[N][N],ans;
bool vis[N][N];
struct node{
	ll id,v;
};
bool operator<(node x,node y){
	return x.v>y.v;
}
vector<node> a[N],in[M];
priority_queue<node> q;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
bool cmp(node x,node y){
	return x.v<y.v;
}
void bfs(ll x){
	memset(dis[x],127,sizeof(dis[x]));
	dis[x][x]=0;
	q.push((node){x,0});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(vis[x][u.id])continue;
		vis[x][u.id]=1;
		for(ll k=1;k<=a[u.id][0].id;k++){
			node w=a[u.id][k];
			for(ll i=1;i<=in[w.id][0].id;i++){
				node v=in[w.id][i];
				if(u.v+v.v+w.v<dis[x][v.id]){
					dis[x][v.id]=u.v+v.v+w.v;
					q.push((node){v.id,dis[x][v.id]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); Q=read();
	for(ll i=1;i<=m;i++){
		w[i]=read();
		in[i].push_back((node){0,-inf});
	}
	for(ll i=1;i<=n;i++){
		ll x,y;
		x=read();
		a[i].push_back((node){x,-inf});
		for(ll j=1;j<=a[i][0].id;j++){
			x=read(); y=read();
			a[i].push_back((node){x,y});
			in[x].push_back((node){i,y});
			in[x][0].id++;
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for(ll i=1;i<=n;i++)bfs(i);
	while(Q--){
		ll x,y;
		x=read(); y=read(); ans=inf;
		for(ll i=1;i<=in[x][0].id;i++){
			for(ll j=1;j<=in[y][0].id;j++){
				node u=in[x][i],v=in[y][j];
				ans=min(ans,dis[u.id][v.id]+u.v+v.v+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
