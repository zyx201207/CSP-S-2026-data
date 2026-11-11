#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M=1e6+10;
const long long inf=1e18;
long long read(){
	long long x=0;
	int flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*flag;
}
int c,n,m,d,q;
int w[M];
int a[N][N];
int k[N];
long long t[N][N];
long long dis[N][N];
vector<pair<int,int> > e[M];
vector<pair<int,int> > g[M];
long long disn[M];
int book[M];
void dij(int st){
	memset(disn,0x3f,sizeof(disn));
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;
	memset(book,0,sizeof(book));
	disn[st]=0;
	q.push({0,st});
	while(!q.empty()){
		auto u=q.top().second;
		q.pop();
		if(book[u]) continue;
		book[u]=1;
		for(auto it:e[u]){
			int v=it.second;
			int w=it.first;
			if(disn[v]>disn[u]+w){
				disn[v]=disn[u]+w;
				q.push({disn[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
			t[i][j]=read();
			e[a[i][j]+m].push_back({t[i][j],i});
			e[i].push_back({t[i][j],a[i][j]+m});
			g[a[i][j]].push_back({t[i][j],i});
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++) dis[i][j]=disn[j];
	}
	while(q--){
		int x,y;
		x=read();
		y=read();
		long long ans=inf;
		for(auto it1:g[x]){
			for(auto it2:g[y]){
				int u=it1.second;
				int v=it2.second;
				long long t1=it1.first;
				long long t2=it2.first;
				ans=min(ans,dis[u][v]+t1+t2+w[x]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}