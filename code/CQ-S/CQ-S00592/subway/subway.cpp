#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=505,M=5e5+5,In_F=1e18;
ll c,n,m,d,Q;
ll w[M];
struct eg{
	ll f,t,n,l;
}g[M*50];ll ig=0;
ll h[N+M];
ll dis[N+M];
bool vis[N+M];
struct asd{
	ll id,z;
};
priority_queue<asd> q;
//±àºÅ£º1~mÕ¾Ì¨		m+1~m+nÏßÂ· 
bool operator < (const asd & a,const asd & b){
	return a.z>b.z;
}
void dij(ll f,ll t){
	memset(dis,0x3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!q.empty())q.pop();
	dis[f]=0;
	q.push({f,0});
	while(!q.empty()){
		asd x=q.top();
		q.pop();
		if(vis[x.id])continue;
		vis[x.id]=true;
		if(x.id==t)return ;
		for(ll i=h[x.id];i;i=g[i].n){
			ll y=g[i].t,l=g[i].l;
			if(dis[x.id]+l<dis[y]){
				dis[y]=dis[x.id]+l;
				q.push({y,dis[y]});
			}
		}
	}
	return ;
}
void A_dd_(ll a,ll b,ll c){
	g[++ig].f=a;
	g[ig].t=b;
	g[ig].l=c;
	g[ig].n=h[a];
	h[a]=ig;
}
void Get_in(){
	cin>>c>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			A_dd_(a,i+m,t);
			A_dd_(i+m,a,t);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Get_in();
	for(ll i=1;i<=Q;i++){
		ll a,b;
		cin>>a>>b;
		dij(a,b);
		cout<<dis[b]+w[a]+w[b]<<'\n';
	}
	
	return 0;
}
