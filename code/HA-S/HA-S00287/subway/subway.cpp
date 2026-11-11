/*永远铭记------丁浩文------史诗级大帅哥*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pii pair<int,int>
#define pll pair<ll,ll>
ll read(){
	char ch=getchar();
	int f=1;
	ll x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=1e6+999;
const ll INF=2e18+999;
int n,m;
int c,d,q;
ll w[N];
ll k[1000];
vector<pll>zhan[N];
ll dis[609][609];
//io
void input(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			ll a=read(),t=read();
			zhan[a].push_back({i,t});
		}
	}
}
//build
void build(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<zhan[i].size();j++){
			for(int k=0;k<j;k++){
				pll u=zhan[i][j];
				pll v=zhan[i][k];
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
				dis[v.first][u.first]=min(dis[v.first][u.first],v.second+u.second);
			}
		}
	}
}
//floyed
void floyed(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
//solve
void solve(){
	for(int p=1;p<=q;p++){
		ll x=read(),y=read();
		ll ans=INF;
		if(x==y)ans=0;
		for(int i=0;i<zhan[x].size();i++){
			for(int j=0;j<zhan[y].size();j++){
				ll u=zhan[x][i].first;
				ll v=zhan[y][j].first;
				ans=min(ans,dis[u][v]+w[x]+zhan[x][i].second+w[y]+zhan[y][j].second);
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);




	input();
	build();
	floyed();
	solve();
	return 0;
}

