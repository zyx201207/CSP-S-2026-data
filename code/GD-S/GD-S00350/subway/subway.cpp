#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f,N=20005,M=505;
int n,m;
int wt[N],a[M][N],t[M][N];
int zdl[M][M];//i到j换乘时间 min
vector<int>hc[M];//站点i所能到达的线路 
	int hct[N][N];//i到j直接换乘时间（若有）
struct edge{
	int to;
	int w;
	bool operator<(const edge&s)const{
		return w>s.w;
	}
};//建边的结构体 
vector<edge> ed[M];

void added(int u,int v,int w){
	
	if(v<=n and u<=n){
		ed[u].push_back({v,w});
	
	}
	return;
	
}//加边 
 
void dijkstra(int x){//两条线路间的最短换乘路径 
	int dis[M];
	bool vis[M]={0};
	priority_queue<edge>b;
	b.push({x,0});
	for(int i=0;i<=n;i++){
		dis[i]=INF;
	}
	dis[x]=0;
	while(b.size()){
		edge eg=b.top();
		b.pop();
		int y=eg.to;
		if(vis[y])continue;
		vis[y]=1;
		for(int i=0;i<ed[y].size();i++){
			int z=ed[y][i].to;
			if(!vis[z]){
				dis[z]=min(dis[z],ed[y][i].w+eg.w);
				b.push({z,dis[z]});
				zdl[x][z]=dis[z];
			}
		}
		
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);//别忘了freopen 
	freopen("subway.out","w",stdout);//别忘了freopen 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	 
	
	for(int i=1;i<=m;i++){
		cin>>wt[i];
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aij,tij;
			cin>>aij>>tij;
			a[i][aij]=j;
			hc[aij].push_back(i);
			t[i][aij]=tij;//把i号线的站名输入，存储其在线上的编号和站台时间 
		}
	}
	for(int i=1;i<=m;i++){
		for(auto &j:hc[i]){
			for(auto &k:hc[i]){
				if(j==k)continue;
				if(hct[j][k]==0){
					hct[j][k]=t[j][i]+t[k][i];
					//hct[k][j]=hct[j][k];
				}
				else{
					hct[j][k]=min(hct[j][k],t[j][i]+t[k][i]);
					//hct[k][j]=hct[j][k];
				}//存i到j时间（可能不是最短） 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;j++){
			if(hct[i][j]){
				added(i,j,hct[i][j]);
				added(j,i,hct[i][j]);
			}//加边dijkstra 
		}
	}
	
	for(int i=1;i<=n;i++){
		dijkstra(i);
		
		
	}
	while(q--){
		int x,y;
		int ans=INF,ans1;
		cin>>x>>y;
		for(auto &j:hc[x]){
			for(auto &k:hc[y]){
				if(j==k){
					ans=0;
					break;
				}
				if(zdl[hc[x][j]][hc[y][k]]){
				ans=min(ans,zdl[hc[x][j]][hc[y][k]]);//算最短 
				ans1=t[hc[x][j]][x]+t[hc[y][k]][y];
				
				}
			}
		}
		cout<<ans+ans1+wt[x]+wt[y]<<endl;
	}

	
	return 0;
}//18:17 累了，调了将近2h的RE，AFO 
