#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5,N=5e2+5;
int c,n,m,d,q;
int w[M],k[N];
ll dis[N][N];
vector<pair<int,int>> e1[M],e[N];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,
	greater<pair<ll,int>>> qu;
int Read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'&&ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	c=Read();n=Read();m=Read(),d=Read();q=Read();
	for(int i=1;i<=m;i++)/* scanf("%d",&w[i]);*/ w[i]=Read();
	for(int i=1;i<=n;i++){
//		scanf("%d",&k[i]);
		k[i]=Read();
		for(int j=1;j<=k[i];j++){
			int a=Read(),t=Read();
//			scanf("%d%d",&a,&t);
			e1[a].emplace_back(i,t);
		}
	}
	for(int i=1;i<=m;i++){
		for(size_t j=0;j<e1[i].size();j++){
			for(size_t k=0;k<e1[i].size();k++){
				if(j!=k){
					int x=e1[i][j].first,y=e1[i][k].first,
						w=e1[i][j].second+e1[i][k].second;
					e[x].emplace_back(y,w);
					e[y].emplace_back(x,w);
				}
			}
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		qu.emplace(0ll,i);
		dis[i][i]=0ll;
		while(!qu.empty()){
			int x=qu.top().second;
			ll d=qu.top().first;
			qu.pop();
			if(d>dis[i][x]) continue;
			for(pair<int,int> tmp:e[x]){
				int y=tmp.first,w=tmp.second;
				if(dis[i][x]+w<dis[i][y]){
					dis[i][y]=dis[i][x]+w;
					qu.emplace(dis[i][y],y);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x=Read(),y=Read();
//		scanf("%d%d",&x,&y);
		ll tmp=1e18;
		for(size_t j=0;j<e1[x].size();j++){
			for(size_t k=0;k<e1[y].size();k++){
				int u=e1[x][j].first,v=e1[y][k].first;
				tmp=min(tmp,dis[u][v]+e1[x][j].second+
					e1[y][k].second);
			}
		}
		printf("%lld\n",tmp+w[x]+w[y]);
	}
	return 0;
}

