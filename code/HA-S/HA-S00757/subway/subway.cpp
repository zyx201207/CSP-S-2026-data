#include<bits/stdc++.h>
using namespace std;
int n,m,d,o,c;
int w[500005];
int dis[505][505];
//int to[1000005],vail[1000005],nxt[1000005],h[1000005],cnt;
//void add(int a,int b,int c){
//	to[++cnt]=b;
//	vail[cnt]=c;
//	nxt[cnt]=h[a];
//	h[a]=cnt;
//}
//bool b[1000005];
//priority_queue<pair<int,int> >q;
//int dis[1000005];
//int dijkstra(int s,int t){
//	for(int i=1;i<=n;i++){
//		dis[i]=0x3fffffff;
//	}
//	dis[s]=0;
//	memset(b,0,sizeof(b));
//	q.push(make_pair(0,s));
//	while(!q.empty()){
//		int u=q.top().second;
//		q.pop();
//		if(b[u]) continue;
//		b[u]=1;
//		for(int i=h[u];i!=0;i=nxt[i]){
//			int v=to[i];
//			if(dis[u]+vail[i]<dis[v]){
//				dis[v]=dis[u]+vail[i];
//				q.push(make_pair(-dis[v],v));
//			}
//		}
//	}
//	return dis[t];
//}
int a[505][505];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>o;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=0x3fffffff;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int ld;
		cin>>ld;
//		for(int j=1;j<=ld;j++){
//			int v,w;
//			cin>>v>>w;
//			a[i][v]=w;
//		}
		for(int j=1;j<=ld;j++){
			int v,w;
			cin>>v>>w;
			dis[i][v]=w;
			dis[v][i]=w;
		}
	}
	
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=n;k++){
//				add(j,k,a[i][j]+a[i][k]);
//				add(k,j,a[i][j]+a[i][k]);
//			} 
//		}
//	}
	while(o--){
		int x,y;
		cin>>x>>y;
//		cout<<dijkstra(x,y)+w[x]+w[y]<<"\n";
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}

//没招了，si磕T2没磕出来，还用了两个半小时 
