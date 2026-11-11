#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
struct node{
	long long v,w;
};
vector<node>g[N];
long long c,n,m,d,q,k,s,e,w[N],ans,a[N],t[N],b[1010][1010];
long long vis[N],book[N];
long long dijkstra()
{
	memset(vis,0x3f,sizeof(vis));
	memset(book,0,sizeof(book));
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
	vis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		long long x=q.top().second;
		if(x==e)return vis[e];
		//cout<<x<<' '<<vis[x]<<'\n';
		q.pop();
		if(book[x])continue;
		book[x]=1;
		for(auto y:g[x]){
			if(y.w+vis[x]<vis[y.v]){
				vis[y.v]=y.w+vis[x];
				q.push({vis[y.v],y.v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c>=7&&c<=11){
		long long a1,a2,t1,t2;
		memset(b,0x3f,sizeof(b));
		for(long long i=1;i<=n;i++){
			cin>>k;
			if(k==1)cin>>a1>>t1;
			else{
				cin>>a1>>t1>>a2>>t2;
				b[a1][a2]=min(t1+t2,b[a1][a2]);
				b[a2][a1]=min(t1+t2,b[a2][a1]);
			}
		}
		for(long long i=1;i<=m;i++)b[i][i]=0;
		for(long long k=1;k<=m;k++)
			for(long long i=1;i<=m;i++)
				for(long long j=1;j<=m;j++)
					b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
		while(q--){
			cin>>s>>e;
			cout<<b[s][e]+w[s]+w[e]<<'\n';
		}
		return 0;
	}
	/*
	if(c>=12&&c<=19){
		vector<long long>g[N];
		long long dis[N],x,y;
		
		for(long long i=1;i<=n;i++){
			cin>>k;
			for(long long j=1;j<=k;j++){
				cin>>x>>y;
				if(!g[x].empty()){
					for(auto t:g[x])
					{
						b[i][t]=1;
						b[t][i]=1;
					}
				}
				g[x].push_back(i);
			}
		}
		/*
		for(long long k=1;k<=n;k++)
			for(long long i=1;i<=n;i++)
				for(long long j=1;j<=n;j++)
					b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
		
		while(q--){
			cin>>s>>e;
			for(auto i:g[s])
				for(auto j:g[e]){
					ans=min(ans,b[i][j]);
				}
			cout<<ans*2*y<<'\n';
		}
		return 0;
		
	}
	*/
	for(long long i=1;i<=n;i++){
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(long long j=1;j<=k;j++)
			for(long long o=j+1;o<=k;o++){
				g[a[j]].push_back({a[o],t[j]+t[o]});
				g[a[o]].push_back({a[j],t[j]+t[o]});
			}
	}
	while(q--){
		cin>>s>>e;
		cout<<dijkstra()+w[e]+w[s]<<'\n';
	}
	return 0;
}
