#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int C,n,m,D,T,wor[N],dis[N][N],book[N];
vector<int>e[N];
struct node{
	int u,w;
}a[N];
void dijkstra(int a,int p){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(book,0,sizeof book);
	dis[a][a]=0;
	q.push({0,a});
	book[a]=1;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		for(int i=0;i<(signed)e[x].size();i+=2){
			int y=e[x][i],w=e[x][i+1];
			if(dis[p][x]+w<dis[p][y]){
				dis[p][y]=dis[p][x]+w;
				if(!book[y]){
					book[y]=1;
					q.push({dis[p][y],y});
				}
			}
		}
		book[x]=0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>T;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++)scanf("%lld",&wor[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j].u,&a[j].w);
			for(int p=j-1;p>=1;p--){
				e[a[j].u].push_back(a[p].u);
				e[a[j].u].push_back(a[j].w+a[p].w);
				e[a[p].u].push_back(a[j].u);
				e[a[p].u].push_back(a[j].w+a[p].w);
			}
		}
	}
	for(int i=1;i<=m;i++) dijkstra(i,i);
	while(T--){
		int l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",dis[l][r]+wor[l]+wor[r]);
	}
	return 0;
}
