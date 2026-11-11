#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=509,maxm=5e5+9;
ll c,n,m,d,q,w[maxm],e[maxn][maxn];
vector<pair<ll,ll> > bel[maxm];
vector<pair<ll,ll> > vec[maxn];
ll read(){
	ll sum=0,ch=getchar(),g=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') g=-1;	
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*g;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++){
		w[i]=read();
	}
	for(ll i=1;i<=n;i++){
		ll k=read();
		for(ll j=1;j<=k;j++){
			ll x=read(),s=read();
			vec[i].push_back(make_pair(x,s));
			bel[x].push_back(make_pair(i,s));
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			e[i][j]=LLONG_MAX;
			if(i==j) e[i][j]=0;
		}
	}
	for(ll u=1;u<=n;u++){
		for(auto i:vec[u]){
			ll x=i.first,w1=i.second;
			for(auto j:bel[x]){
				ll v=j.first,w2=j.second;
				//cout<<u<<' '<<v<<' '<<x<<' '<<w1+w2<<endl;
				e[u][v]=min(e[u][v],w1+w2);
			}
		}
	}
	/*for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(e[i][j]==LLONG_MAX) cout<<"/ ";
			else cout<<e[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(e[i][k]==LLONG_MAX||e[k][j]==LLONG_MAX) continue;
				if(e[i][k]+e[k][j]<e[i][j]) e[i][j]=e[i][k]+e[k][j];
			}
		}
	}
	for(ll k=1;k<=q;k++){
		ll x=read(),y=read(),ans=LLONG_MAX;
		for(auto i:bel[x]){
			ll u=i.first,w1=i.second;
			for(auto j:bel[y]){
				ll v=j.first,w2=j.second;
				ans=min(ans,e[u][v]+w1+w2);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}