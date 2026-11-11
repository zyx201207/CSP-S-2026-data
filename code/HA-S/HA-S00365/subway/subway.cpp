#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=510;
const int M=5e6+10;
const int mod=998244353;
const ll inf=0x3f3f3f3f3f3f3f3f;
int maxx=N-10;
ll n,m,ans,cnt,d,T;
ll w[M],k[M];
ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
ll ppow(ll n,ll m){ll s=1;while(m){if(m&1)s=(s*n)%mod;n=(n*n)%mod;m>>=1;}return s;}
vector<pair<ll,ll>>g[M];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
ll dis[M],vis[M];
void dij(int st){
	for(int i=1;i<=cnt;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[st]=0;
	q.push({0,st});
	while(q.size()){
		int x=q.top().se;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto o:g[x]){
			int y=o.fi;
			int z=o.se;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				q.push({dis[y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>m>>n>>d>>T;
	for(int i=1;i<=n;i++){
		w[i]=read();
	}
	cnt=n;
	for(int i=1;i<=m;i++){
		cin>>k[i];
		cnt++;
		for(int j=1;j<=k[i];j++){
			ll t=read(),a=read();
//			cout<<cnt<<' '<<t[i][j]<<"?"<<a[i][j]<<'\n';
			g[cnt].pb({t,a});
			g[t].pb({cnt,a});
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<'\n';
//		for(auto o:g[i])cout<<o.fi<<' '<<o.se<<'\n';
//	}
	while(T--){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		dij(x);
		cout<<dis[y]+ans<<'\n';
	}
}
