#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct question{
	ll x,y;
}x[100005]; 
ll c,n,m,d,q,w[500005],a[500005],t[500005],ans[100005],id[100005],dis[500005];
vector<pair<ll,ll>>g[500005];
bitset<500005>v;
ll read(){
	ll c=getchar(),f=1,x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void write(ll x){
	if(x==0)return;
	if(x<0){putchar('-');x=-x;}
	write(x/10);
	putchar(x%10+'0');
}
void dij(ll s){
	memset(dis,0x3f,sizeof(dis));
	v=0;
	dis[s]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
	q.push({0,s});
	while(q.size()){
		ll x=q.top().first,y=q.top().second;
		q.pop();
		if(v[y])continue;
		for(auto i:g[y]){
			if(dis[y]+i.first<dis[i.second]){
				dis[i.second]=dis[y]+i.first;
				q.push({dis[i.second],i.second});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(ll i=1;i<=m;i++)w[i]=read();
	for(ll i=1,k;i<=n;i++){
		k=read();
		for(ll j=1;j<=k;j++){
			a[j]=read();t[j]=read();
		}
		for(ll j=1;j<k;j++){
			for(ll l=j+1;l<=k;l++){
				g[a[j]].push_back({t[j]+t[l],a[l]});
				g[a[l]].push_back({t[j]+t[l],a[j]});
			}
		}
	}
	for(ll i=1;i<=q;i++){
		x[i].x=read();x[i].y=read();
	}
	for(ll i=1;i<=q;i++)id[i]=i;
	sort(id+1,id+q+1,[](ll a,ll b){return x[a].x<x[b].x;});
	for(ll i=1;i<=q;i++){
		ll s=x[id[i]].x;
		dij(s);
		while(x[id[i]].x==s)ans[id[i]]=dis[x[id[i]].y]+w[x[id[i]].x]+w[x[id[i]].y],i++;
		i--;
	}
	for(ll i=1;i<=q;i++){write(ans[i]);putchar('\n');}
	return 0; 
}
