#include<bits/stdc++.h>

using namespace std;

const int MAXM = 5e4+5;
const int MAXN = 505;
const int MAXQ = 1e5+5;
int c;
int n,m; //地铁线路数，地铁站数 
int d; //每个地铁站最多被几条线路经过 
int q; //出行计划数 

int w[MAXM]; //地铁口到站厅 
int k[MAXN];//第i条线路经过的地铁站数
int a[MAXN][MAXM]; //某条线路经过的某个地铁站 
int t[MAXM][MAXN]; //某地铁站站厅走到第i条线路站台 

struct node1{
	int u,v,w;
}Edge[MAXN];//用图来建立：线路中两个地铁站的连接
 
struct node2{
	int x,y;
}plan[MAXQ]; 

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i]; //地铁口走到站厅时间 
	} 
	
	for(int i=1;i<=n;i++){
		cin>>k[i]; //第i条线路经过的地铁站数
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]; //第i条线路经过的第j个地铁站 
			int station = a[i][j];
			cin>>t[i][station]; //a[i][j]站厅和i线路之间的距离			 
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>plan[i].x;
		cin>>plan[i].y;
	} 
	
	for(int i=1;i<=n;i++){
		int u = a[i][1];
		int v = a[i][2];
		int w = t[i][u]+t[i][v];
		
		Edge[i].u = u;
		Edge[i].v = v;
		Edge[i].w = w;
	}

	
	for(int i=1;i<=q;i++){
		long long ans = Edge[1].w;
		ans = plan[i].x+plan[i].y;
		cout<<ans<<endl;
	} 
	
	return 0;
}

