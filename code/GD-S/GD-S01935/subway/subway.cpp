#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=510;
typedef long long ll;
ll c,n,m,d,q;
ll k;
ll x,y,z;
ll a[N],D[N];
bool vis[N];
vector<ll>lu[M];
struct nd{
	ll dis,u;
	operator>(const nd&b)const{return u>b.u;}
};
vector<nd>e[N];
void dij(ll s){
	memset(D,0x3f,sizeof D);
	memset(vis,0,sizeof vis);
	priority_queue<nd,vector<nd>,greater<nd> >q;
	q.push({D[s]=0,s});
//	vis[s]=1;
	while(q.size()){
		ll u=q.top().u;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(nd to:e[u]){
			if(D[to.u]>D[u]+to.dis)q.push({D[to.u]=D[u]+to.dis,to.u});
		}
	}
}
void add(ll x,ll y,ll z){
	e[x].push_back({z,y});
}
struct MD{
	ll fr,to,idx;
}ASK[N];
ll ANS[N];
int main(){
	freopen("subway.in","r",stdin);
//	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i)cin>>a[i];
	for(ll i=1;i<=n;++i){
		cin>>k;
		for(ll j=1;j<=k;++j){
			cin>>x>>y;
			add(m+i,x,y),add(x,m+i,y);
		}
	}
	if(q<=10000){
		for(ll i=1;i<=q;++i){
			cin>>x>>y;
			dij(x);
			cout<<D[y]+a[y]+a[x]<<endl;
		}	
	}else 
//	if(c<=15)
	{
		memset(ANS,0x3f,sizeof ANS);
		for(ll i=1;i<=q;++i){
			cin>>x>>y;
			ASK[i]={x,y,i};
		}
		for(ll i=1;i<=n;++i){
			dij(m+i);
			for(ll j=1;j<=q;++j){
				ANS[j]=min(ANS[j],D[ASK[j].to]+D[ASK[j].fr]+a[ASK[j].to]+a[ASK[j].fr]);
			}
		}
		for(int i=1;i<=q;++i)cout<<ANS[i]<<endl;
	}
	return 0;
}

