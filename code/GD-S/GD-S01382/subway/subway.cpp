#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N=5e5+7;
ll n,m,D,q,w[N],siz[N];
vector<pll>line[N];
vector<pll>station[N];
vector<ll>d[N];
void dij(ll st){
	priority_queue<pll>pq;
	d[st].push_back(0);
	for(int i=1;i<=m;i++){
		if(i==st)d[st].push_back(0);
		else d[st].push_back(1e18);
	}
	pq.push(make_pair(0,st));
	while(!pq.empty()){
		ll u=pq.top().second;
		pq.pop();
		//cout<<u<<",";
		for(auto x:line[u]){
			ll sta=x.first,walk1=x.second;
			for(auto y:station[sta]){
				ll v=y.first,walk2=y.second;
				if(u==v)continue;
				ll nd=d[st][u]+walk1+walk2;
				if(d[st][v]>nd){
					d[st][v]=nd;
					pq.push(make_pair(-nd,v));
				}
			}
		}
	}
}
void Dbug(ll type){
	if(type==1){
		for(int i=1;i<=n;i++){
			printf("\nLine£º%lld;",i);
			for(auto x:line[i]){ 
				printf("{Station£º%lld£»Time£º%lld},",x.first,x.second);
			}
		}
	}else if(type==2){
		for(int i=1;i<=m;i++){
			printf("\nStation£º%lld;",i);
			for(auto x:station[i]){ 
				printf("{Line£º%lld£»Time£º%lld},",x.first,x.second);
			}
		}
	}else if(type==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<d[i][j]<<" ";
			}
			cout<<endl;
		}
	}else if(type==998244353){
		Dbug(1);
		Dbug(2);
		cout<<endl;
		Dbug(3);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	bool flagA=true,flagB=true;
	ll J=-998244353;
	ll C;scanf("%lld",&C);
	scanf("%lld %lld %lld %lld",&n,&m,&D,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&siz[i]);
		if(siz[i]>2)flagA=false;
		for(int j=0;j<siz[i];j++){
			pll tmp; 
			scanf("%lld %lld",&tmp.first,&tmp.second);
			if(J==-998244353)J=tmp.second;
			else if(J!=tmp.second)flagB=false;
			station[tmp.first].push_back(make_pair((ll)(i),tmp.second));
			line[i].push_back(tmp);
		}
	} 
	for(int i=1;i<=m;i++)dij(i);
	while(q--){
		ll s,t;scanf("%lld %lld",&s,&t);
		ll ans=9e18;
		for(auto x:station[s]){
			for(auto y:station[t]){
				ll line1=x.first,line2=y.first;
				ll w1=x.second,w2=y.second;
				ans=min(ans,d[line1][line2]+w1+w2);
			}
		}
		cout<<ans+w[s]+w[t]<<endl;
	}
	return 0;
} 
