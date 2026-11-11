#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
typedef long long ll;
const int N=505;
const int M=5e5+5;
const ll inf=1e16;
ll read(){
	ll x=0; bool f=1;
	char c=gc();
	while(c>'9'||c<'0'){
		if(c=='-') f=0;
		c=gc();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=gc();
	}
	return f?x:-x;
}
void put(ll x){
	if(x<0){x=-x;pc('-');}
	if(x>9)put(x/10);
	pc(x%10+'0');
}
ll c,n,m,d,q;
ll W[M];
ll k[N];
vector<ll> a[N],t[N],v[M];
map<ll,ll> mp[N];
ll dis[M];
void spfa(ll s){
	bool b[M];
	for(int i=1;i<=m;++i){
		dis[i]=inf;
		b[i]=0;
	}
	dis[s]=0;
	queue<ll> q;
	q.push(s);b[s]=1;
	while(!q.empty()){
		ll f=q.front(); q.pop(); 
		if(c<12||c>15) b[f]=0;
		for(int I=0;I<int(v[f].size());++I){
			ll li=v[f][I];
			ll F=mp[li][f];
			for(int i=1;i<=k[li];++i){
				int to=a[li][i];
				ll w=t[li][i]+t[li][F];;
				if(dis[f]+w<dis[to]){
					dis[to]=dis[f]+w;
					if(!b[to]){
						q.push(to);
						b[to]=1;
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;++i) W[i]=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j){
			ll x=read();
			a[i].push_back(x);
			v[x].push_back(i);
			mp[i][x]=j-1;
			t[i].push_back(read());
		}
	}
	while(q--){
		ll x=read(),y=read();
		spfa(x);
		ll ans=dis[y];
		spfa(y);
		ans=min(ans,dis[x]);
		put(W[x]+W[y]+ans);pc('\n');
	}
	return 0;
}
