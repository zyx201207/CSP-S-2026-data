#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int N = 5*1e5+10;
int c,n,m,d,q,w[N];

vector<pii > a[N];// 车站 （路线，时间） 
vector<pii > b[N];// 存图（距离，编号） 
int p[510][N];//车站 路线 

int dis[10010];
bool vis[10010];
int cnt=0,cmt=0;
int nx[10010];
int rex;

void dijkstra(int x){
	for(int i=1;i<=cnt;i++) vis[i]=0,dis[i]=0x3f3f3f3f;
	dis[x]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;//距离 编号 
	q.push({0,x});
	while(!q.empty()){
		int w=q.top().second;
		if(vis[w]) continue;
		for(int i=0;i<(int)b[w].size();i++){
			int u=b[w][i].first;
			int v=b[w][i].second;
			if(dis[v]>dis[w]+u){
				dis[v]=dis[w]+u;
				q.push({dis[v],v});
			}
		}
	} 
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、出行计划数。
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
			cnt++;
			p[x][i]=cnt;
			nx[cnt]=i;
			if(j<k){
				b[cnt+1].push_back({0,cnt});
				b[cnt].push_back({0,cnt+1});
				cmt+=2;
				//cout<<cnt<<" to "<<cnt+1<<endl; 
			}
			//cout<<"		x="<<x<<" cnt="<<cnt<<endl;
		}
	} 
	for(int o=1;o<=m;o++){
		for(int i=0;i<(int)a[o].size();i++){
			for(int j=i+1;j<(int)a[o].size();j++){
				int line1=a[o][i].first;
				int line2=a[o][j].first;
				int time=a[o][i].second+a[o][j].second;
				//cout<<line1<<" "<<line2<<" "<<time<<endl;
				b[p[o][line1]].push_back({time,p[o][line2]});
				b[p[o][line2]].push_back({time,p[o][line1]});
				cmt+=2; 
			}
		}
	}
//	for(int i=1;i<=cnt;i++){
//		for(int j=0;j<(int)b[i].size();j++){
//			cout<<i<<" to "<<b[i][j].second<<" ,w= "<<b[i][j].first<<endl;
//		}
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f;
		for(int j=0;j<(int)a[x].size();j++){
			dijkstra(p[i][a[x][j].first]);
			ans=min(ans,a[x][j].second+a[y][0].second+dis[p[i][a[y][0].first]]);
		}
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<endl; 
	}
}
