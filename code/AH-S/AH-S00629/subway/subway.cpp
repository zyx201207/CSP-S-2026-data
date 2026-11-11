#include<bits/stdc++.h>
using namespace std;
const int N=5005;
struct node{
	int nxt,to;
	long long w;
}e[10000005];
int cnt,h[N],A[N],B[N];
long long w[N],a[N][N],dis[N][N],t[N][N],k[N],tim[N];
void add(int x,int y,int z){
	e[++cnt].nxt=h[x];
	e[cnt].to=y;
	e[cnt].w=z;
	h[x]=cnt;
}
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
void dij(int s){
	q.push({0,s});
	dis[s][s]=0;
	while(!q.empty()){
		long long d=q.top().first;
		int f=q.top().second;
		q.pop();
		if(d>dis[s][f]) continue;
		for(int i=h[f];i;i=e[i].nxt){
			if(dis[s][e[i].to]>dis[s][f]+e[i].w){
				dis[s][e[i].to]=dis[s][f]+e[i].w;
				q.push({dis[s][e[i].to],e[i].to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f,sizeof(dis));
	int C,n,m,d,Q;
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(n==2){
		long long ti;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j];
				if(tim[a[i][j]]){
					cin>>ti;
					ti+=tim[a[i][j]]; 
				}else cin>>tim[a[i][j]];
				if(i==1) A[a[i][j]]=1;
				else B[a[i][j]]=1;
			}
		}
		while(Q--){
			int x,y;
			cin>>x>>y;
			if((A[x] && A[y]) || (B[x] && B[y])) cout<<tim[x]+tim[y]+w[x]+w[y]<<"\n";
			else cout<<tim[x]+tim[y]+w[x]+w[y]+ti<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int p=1;p<j;p++){
				add(a[i][j],a[i][p],t[i][j]+t[i][p]);
				add(a[i][p],a[i][j],t[i][j]+t[i][p]);
			}
		}
	}
	for(int i=1;i<=m;i++) dij(i);
	while(Q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
