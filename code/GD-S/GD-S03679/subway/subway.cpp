#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010101;
ll c,n,m,d,qu,cnt[N],head[N],tot,pos[N][30],fee[N][30],num[N],p[N];
ll dis[N],vis[N],ans[N],x[N],y[N],val[510][510];
struct tt{ll to,next,w,id;}e[N];
struct node{
	ll u,dis;
	bool operator<(const node &a)const{
		return dis<a.dis;
	}
};
priority_queue<node>q;
void add(ll u,ll v,ll w){
	e[++tot].to=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}
void js(ll s){
	q.push({s,0});
	for(int i=1;i<=n+m+m;i++)dis[i]=1e15,vis[i]=0;
	dis[s]=0;
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(int i=head[now.u];i;i=e[i].next){
			ll v=e[i].to,w=e[i].w;
			if(dis[now.u]+w<=dis[v]){
				dis[v]=dis[now.u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
bool cmp(ll a,ll b){
	return x[a]<x[b];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)cin>>cnt[i];
	for(int i=1;i<=n;i++){
		ll k,u=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll v,w;
			cin>>v>>w;
			pos[v][++num[v]]=i;
			fee[v][num[v]]=w;
			add(v,i+m,cnt[v]+w);
			add(i+m,n+m+v,cnt[v]+w);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)val[i][j]=1e15;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=num[i];j++){
			for(int l=j+1;l<=num[i];l++){
				ll u=pos[i][j],v=pos[i][l];
				if(val[u][v]<=fee[i][j]+fee[i][l])continue;
				add(u+m,v+m,fee[i][j]+fee[i][l]);
				add(v+m,u+m,fee[i][j]+fee[i][l]);
				val[u][v]=val[v][u]=fee[i][j]+fee[i][l];
			}
		}
	}
	for(int i=1;i<=qu;i++){
		cin>>x[i]>>y[i];
		if(x[i]>y[i])swap(x[i],y[i]);
		cnt[i]=i; 
	}
	sort(cnt+1,cnt+qu+1,cmp);
	for(int i=1;i<=qu;i++){
		if(!p[x[cnt[i]]]){
			js(x[cnt[i]]);
			p[x[cnt[i]]]=1;
		}
		ans[cnt[i]]=dis[y[cnt[i]]+n+m];
	}
	for(int i=1;i<=qu;i++)cout<<ans[i]<<"\n";
	return 0;
} 
