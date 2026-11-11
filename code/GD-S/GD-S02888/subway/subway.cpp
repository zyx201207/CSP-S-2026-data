#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510,M=5e5+10,inf=1e15,md=1e9+7;
ll read(){
	ll ans=0,f=1;
	char s=' ';
	while(!(s>='0'&&s<='9')){
		s=getchar();
		if(s=='-')f=-1;
	}
	while(s>='0'&&s<='9'){
		ans=ans*10+s-'0';
		s=getchar();
	}
	return ans*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar('0'+x%10);
}
ll n,m,Q,w[M],dis[N][N];
vector<pair<ll,ll>>dt[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();n=read();m=read();read();Q=read();
	for(ll i=1;i<=m;i++)w[i]=read();
	memset(dis,0x3f,sizeof dis);
	for(ll i=1;i<=n;i++){
		dis[i][i]=0;
		ll kk=read();
		for(ll j=1;j<=kk;j++){
			ll a=read(),t=read();
			dt[a].push_back({i,t});
		}
	}
	for(ll i=1;i<=m;i++)if(dt[i].size()>1){
		for(ll it=0;it<dt[i].size();it++)
			for(ll iit=it+1;iit<dt[i].size();iit++){
				ll u=dt[i][it].first,v=dt[i][iit].first,t=dt[i][it].second+dt[i][iit].second;
				dis[u][v]=dis[v][u]=min(dis[u][v],t);
			}
	}
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)if(i!=k&&j!=k&&dis[i][k]<=inf&&dis[j][k]<=inf)
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[j][k]);
	while(Q--){
		ll S=read(),T=read(),ans=inf;
		for(auto it:dt[S])
			for(auto iit:dt[T]){
				ll sum=w[S]+w[T]+it.second+iit.second+dis[it.first][iit.first];
				ans=min(ans,sum);
			}
		write(ans);
		putchar('\n');
	}
	return 0;
}

