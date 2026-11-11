#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=210;
const int M=410;
struct P{
	int v,w;
	bool operator < (const P &W)const{
		return w>W.w;
	}
};
int n,m,d,q;
int w[M],k[N];
int dis[82100];
bool st[82100];
vector<int>a[N],lid[N];
int t[N][M],x[N][N];
vector<P>g[82100];
void dij(int s,int e){
	int ans=1e18;
	for(int i=1;i<=n*m;i++)st[i]=0,dis[i]=1e14;
	priority_queue<P>q;
	for(int i=0;i<lid[s].size();i++){
		q.push({s+(lid[s][i]-1)*m,t[lid[s][i]][s]});
		dis[s+(lid[s][i]-1)*m]=t[lid[s][i]][s];
	}
	while(q.size()){
		P t=q.top();
		int u=t.v;
		q.pop();
		st[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(st[v])continue;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	for(int i=0;i<n;i++){
		if(st[e+i*m]==1)ans=min(ans,dis[e+i*m]+t[i+1][e]);
	}
	cout<<ans+w[s]+w[e]<<'\n';
}
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int same=-1e9;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int aij,tij;
			cin>>aij>>tij;
			lid[aij].push_back(i);
			a[i].push_back(aij);
			t[i][aij]=tij;
			if(same==-1e9)same=tij;
			else{
				if(tij!=same)f=0;
			}
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)x[i][j]=1e18;
			}
		}
		for(int i=1;i<=m;i++){
			if(lid[i].size()>1){
				for(int j=0;j<lid[i].size();j++){
					for(int k=j+1;k<lid[i].size();k++){
						x[lid[i][j]][lid[i][k]]=x[lid[i][k]][lid[i][j]]=1;
					}
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(x[i][j]!=1e18)continue;
					if(x[i][k]&&x[k][j]){
						x[i][j]=min(x[i][j],x[i][k]+x[k][j]);
					}
				}
			}
		}
		while(q--){
			int xx,y;
			cin>>xx>>y;
			int ans=1e18;
			for(int i=0;i<lid[xx].size();i++){
				for(int j=0;j<lid[y].size();j++){
					ans=min(ans,x[lid[xx][i]][lid[y][j]]);
				}
			}
			cout<<same*ans*2+same*2+w[xx]+w[y]<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			g[a[i][j-1]+(i-1)*m].push_back({a[i][j]+(i-1)*m,0});
			g[a[i][j]+(i-1)*m].push_back({a[i][j-1]+(i-1)*m,0});
		}
	}
	for(int i=1;i<=m;i++){
		if(lid[i].size()>1){
			for(int j=0;j<lid[i].size();j++){
				for(int k=j+1;k<lid[i].size();k++){
					g[i+(lid[i][j]-1)*m].push_back({i+(lid[i][k]-1)*m,t[lid[i][j]][i]+t[lid[i][k]][i]});
					g[i+(lid[i][k]-1)*m].push_back({i+(lid[i][j]-1)*m,t[lid[i][j]][i]+t[lid[i][k]][i]});
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x,y);
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,T=1;
	cin>>c;
	while(T--)solve();
	return 0;
}