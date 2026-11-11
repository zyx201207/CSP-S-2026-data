#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=4e3+10;
const int inf=0x3f3f3f3f;
long long c,t,n,k,dis[N][N],d[N],ans;
vector<int> g[N];
void bfs(int s){
	int vis[N]={};
	queue<pair<int,int> > q;
	q.push({s,0});
	while(!q.empty()){
		long long u=q.front().first;
		long long d=q.front().second;
		q.pop();
		if(vis[u])  continue;
		vis[u]=1;
		dis[s][u]=min(dis[s][u],d);
		for(int v:g[u]){
			if(vis[v]!=1){
				q.push({v,d+1});
			}
		}
	}
}
class dsu{
	vector<int> f;
	int n;
public:
	dsu(int n):n(n){
		f.resize(n+5);
		for(int i=1;i<=n;i++)  f[i]=i;
	}
	int find(int x){
		return f[x]==x?f[x]:f[x]=find(f[x]);
	}
	void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y)  f[x]=y;
	}
	int count(){
		int cnt[N]={},res=0;
		for(int i=1;i<=n;i++)  cnt[find(i)]++;
		for(int i=1;i<=n;i++)  res+=cnt[i];
		return res;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(dis,inf,sizeof dis);
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v]=dis[v][u]=0;
		}
		for(int i=1;i<=n;i++)  bfs(i);
		ans=inf;
		for(int i=1;i<(1<<n);i++){
			int t=i,cnt=0,j=n,v[N]={};
			dsu a(n);
			while(t){
				if(t&1){
					cnt++;
					for(int v:g[j])  a.merge(j,v);
					v[j]=1;
				}
				j--;
				t>>=1;
			}
			if(a.count()<=2&&cnt==k){
				long long r=-inf;
				for(int i=1;i<=n;i++){
					d[i]=inf;
					for(int j=1;j<=n;j++){
						if(v[j]==1)  d[i]=min(d[i],dis[i][j]);
					}
					r=max(r,d[i]);
				}
				ans=min(ans,r);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

