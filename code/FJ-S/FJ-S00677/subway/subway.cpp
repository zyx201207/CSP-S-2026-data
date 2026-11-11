#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
typedef long long ll;
int c,n,m,d,q;
int w[M];

//1~8
ll f[405][405];
vector<int> v[405];
int dis[405];
const ll maxn=1e16+5;
void sol1(){
	for(int i=1;i<=403;++i){
		for(int j=1;j<=403;++j){
			if(i!=j)f[i][j]=maxn;
		}
	}
	int tot=0;
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		int p=tot;
		for(int j=1;j<=k;++j){
			++tot;
			int a;cin>>a>>dis[tot];
			v[a].push_back(tot);
		}
		for(int j=p+1;j<tot;++j)f[j][j+1]=f[j+1][j]=0;
	}
	
	for(int i=1;i<=m;++i){
		for(int j=0;j<v[i].size();++j){
			for(int k=j+1;k<v[i].size();++k){
				f[v[i][j]][v[i][k]]=f[v[i][k]][v[i][j]]=dis[v[i][k]]+dis[v[i][j]];
			}
		}
	}
	
	for(int k=1;k<=tot;++k){
		for(int i=1;i<=tot;++i){
			for(int j=1;j<=tot;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}	
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=maxn,s;
		for(int i=0;i<v[x].size();++i){
			for(int j=0;j<v[y].size();++j){
				s=f[v[x][i]][v[y][j]]+dis[v[x][i]]+dis[v[y][j]];
				ans=min(ans,s);
			}
		} 
		cout<<w[x]+w[y]+ans<<'\n';
	}
	//¿Õ¼ä»»Ê±¼ä 
}

//
ll dist[1005][1005];
typedef pair<int,ll> pii;
typedef pair<ll,int> pij;
vector<pii> a[1005];
bool g[1005];
void sol2(){
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			dist[i][j]=maxn;
		}
	}
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		int l,r;
		if(k==1)cin>>l>>r;
		else{
			ll ls,rs;cin>>l>>ls>>r>>rs;
			a[l].push_back(make_pair(r,ls+rs));
			a[r].push_back(make_pair(l,ls+rs));
		}
	}
	for(int i=1;i<=m;++i){
		dist[i][i]=0;
		for(int j=1;j<=m;++j)g[j]=0;
		//g[i]=1;
		priority_queue<pij> qq;
		qq.push(make_pair(-dist[i][i],i));
		while(!qq.empty()){
			int l=qq.top().second;qq.pop();
			if(g[l])continue;g[l]=1;
			for(int j=0;j<a[l].size();++j){
				int r=a[l][j].first;
				ll w=a[l][j].second;
				if(dist[i][r]>dist[i][l]+w){
					dist[i][r]=dist[i][l]+w;
					qq.push(make_pair(-dist[i][r],r));
				}
			} 
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<w[x]+w[y]+dist[x][y]<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	if(c<=8){
		sol1();
		return 0;	//32pts
	}
	if(c<=11){  //12pts
		sol2();
		return 0;
	}
	return 0;
} 
