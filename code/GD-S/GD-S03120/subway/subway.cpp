#include<bits/stdc++.h>
using namespace std;

const int N=500005;

typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll c,n,m,d,q;
ll w[500005];
vector<pair<ll,ll> > G[505];

//A
vector<pair<ll,ll> > GG[505];//ÏßÂ· 
ll dis[N];
bool vis[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		ll k=read();
		if(k==2){
			ll a=read(),t1=read(),b=read(),t2=read();
			GG[a].push_back({b,t1+t2});
			GG[b].push_back({a,t1+t2});
		}else{
			for(int j=1;j<=k;j++){
				ll a=read(),t=read();
				G[a].push_back({i,t});
			}
		}
		
	}
	for(int i=i;i<=q;i++){
		ll ans=0;
		ll x=read(),y=read();
		ans+=w[x]+w[y];
		memset(vis,0,sizeof vis);
		memset(dis,0x3f,sizeof dis);
		priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
		dis[x]=0;
		pq.push({0,x});
		while(pq.size()){
			ll u=pq.top().second;
			pq.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int j=0;j<GG[u].size();j++){
				ll v=GG[u][j].first,w=GG[u][j].second;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					pq.push({dis[v],v});
				}
			}
		}
		cout<<dis[y]+ans<<endl;
	}
	return 0;
}
