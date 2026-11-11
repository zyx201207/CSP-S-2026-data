#include<bits/stdc++.h>
#define ll long long 
#define fg cout<<"！！！！！！！！！！！！！！！！！！！！！！！！！！"<<endl
#define inf (ll)1e18
#define pb push_back
#define mk make_pair
#define pii pair<ll,ll>
#define mt(x) memset(x,0,sizeof(x))
using namespace std;
const int mod=998244353,N=1e6+5;
int M1;
ll read(){
	ll n=0,k=1;
	char c;
	while(c>'9'||c<'0'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+c-'0';
		c=getchar();
	}
	return n*k;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
ll n,K,rt;
vector<int>vt[N];
ll f[105][105],siz[105];
ll dep[N],mx[N],id[N],tot;
void Dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	mx[u]=u;
	id[u]=++tot;
	for(auto v:vt[u]){
		if(v==fa) continue;
		Dfs(v,u);
		if(dep[mx[v]]>dep[mx[u]]) mx[u]=mx[v];
	}
} 
ll tmp[105];
void dfs(int u,int fa,int x){
	siz[u]=1;
	for(int i=0;i<=K;i++) f[u][i]=0;
	f[u][1]=1;
	if(dep[mx[u]]-dep[u]<=x){
		return;
	}
	for(auto v:vt[u]){
		if(v!=fa){
			dfs(v,u,x);
			mt(tmp);
			for(int j=1;j<=siz[u];j++){
				for(int k=1;k<=siz[v]&&j+k<=K;k++){
					tmp[j+k]|=(f[u][j]&f[v][k]);
				}
			}
			memcpy(f[u],tmp,sizeof(f[u]));
			siz[u]+=siz[v];
		}
	}
	for(int j=0;j<=K;j++) f[u][j]=f[u][j+1];
}
vector<pii>res;
ll dis[105][105];
int pd(int u,int v,int x){
	for(int i=1;i<=n;i++){
		if(id[u]<=id[i]&&id[i]<=id[u]+siz[u]-1) continue;
		if(id[v]<=id[i]&&id[i]<=id[v]+siz[v]-1) continue;
		if(min(dis[i][u],dis[i][v])>x) return 0;
	}
	return 1;
}
int check(int x){
	for(int i=1;i<=n;i++){
		tot=0;
		Dfs(i,0);
		dfs(i,0,x);
		res.clear();
		for(int j=1;j<=n;j++){
			for(int k=1;k<=K;k++){
				if(f[j][k]){
					res.pb(mk(k,j));
					break;
				}
			}
		}
		sort(res.begin(),res.end());
		for(auto u:res){
			if(pd(u.second,u.second,x)) return 1;
			for(auto v:res){
				if(u.first+v.first<=K){
					if(pd(u.second,v.second,x)) return 1;
				}else break;
			}
		}
	}
	return 0;
}
void For_aiur(){
	cin>>n>>K;
	for(int i=1;i<=n;i++) vt[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=1;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		vt[u].pb(v);
		vt[v].pb(u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int L=1,R=n,ans=-1;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)) R=mid-1,ans=mid;
		else L=mid+1;
	}
	cout<<ans<<endl;
}
int M2;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio();cin.tie();cout.tie();
	int wlae=1,C;
	cin>>C;
	cin>>wlae;
	while(wlae--) For_aiur();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

1
2

*/
