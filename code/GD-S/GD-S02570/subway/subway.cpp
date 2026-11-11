#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,W,w2[5005][5005],w[5005];
struct Edge{
	int v,w;	
};
//vector<Edge>e[500550];
void addedge(int u,int v,int w){
	//e[u].push_back({v,w});
	w2[u][v]=w;
}
int dis[20004][20004];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			addedge(i+m,a,t);
			addedge(a,i+m,t);
		}
	}
	int N=m+n;
	memset(dis,0x3f,sizeof(dis));
	dis[1][1]=0`;
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(dis[i][j]>dis[i][k]+w2[k][j]){
					dis[i][j]=dis[i][k]+w2[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]+10<<endl;
	}
	return 0;
} 
