#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int M=500005;
const int N=505;
vector<pll> G[M];
int c,n,m,d,q;
int w[M];
ll dist[M];
int linea[M];
int linet[M];
ll ans=0;
ll dj(int start,int goal){
	priority_queue<pll,vector<pll>,greater<pll> > qq;
	dist[start]=0;
	qq.push(make_pair(0,start));
	while(!qq.empty()){
		int d=qq.top().first;
		int u=qq.top().second;
		qq.pop();
		if(d>dist[u])continue;
		if(u==goal)return d;
		for(auto e:G[u]){
			int nd=e.second;
			int v=e.first;
			if(dist[v]>dist[u]+nd){
				dist[v]=dist[u]+nd;
			    qq.push(make_pair(dist[v],v));
			}
		}
	}
	return -1;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		memset(linea,0,sizeof(linea));
		memset(linet,0,sizeof(linet));
		for(int j=1;j<=k;j++)cin>>linea[j]>>linet[j];
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				int ww=linet[u]+linet[v];
				G[linea[u]].push_back(make_pair(linea[v],ww));
				G[linea[v]].push_back(make_pair(linea[u],ww));
			}
		}
	}
	for(int i=1;i<=q;i++){
	    memset(dist,0x3f,sizeof(dist));
		int a,b;
		cin>>a>>b;
		ans=0;
		ans=w[a]+w[b];
		ans+=dj(a,b);
		cout<<ans<<endl;
	}
	return 0;
}
