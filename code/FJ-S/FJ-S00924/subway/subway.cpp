#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+500+5;
int c,n,m,d,ques,x,y,xx,yy,k,dis[N],vis[505][505],ans;
int jl[N];
int the_cost[N];
struct road{int to,cost;};
vector<road>a[N],v[N];
struct node{
	int dis,pos;
	bool operator<(const node &x)const{
		return x.dis<dis;
	}
};
priority_queue<node>q;
void dijkstra(int st){
	while(!q.empty())q.pop();
	for(int i=1;i<=m;i++)dis[i]=LONG_LONG_MAX/100,jl[i]=0;
	q.push((node){0,st});
	dis[st]=0;
	while(!q.empty()){
		x=q.top().pos;
		q.pop();
		if(jl[x])continue;
		jl[x]=1;
		for(int i=0;i<v[x].size();i++){
			y=v[x][i].to;
			if(dis[y]>dis[x]+v[x][i].cost){  
				dis[y]=dis[x]+v[x][i].cost;
				q.push((node){dis[y],y});
			}
		}
	}
	for(int i=1;i<=m;i++)vis[st][i]=dis[i];
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>m>>n>>d>>ques;
	for(int i=1;i<=n;i++)cin>>the_cost[i];
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			/*if(k==1){
				i--;
				m--;
				continue;
			}*/
			a[x].push_back((road){n+i,y});
			a[n+i].push_back((road){x,y});
		}
	}
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)vis[i][j]=LONG_LONG_MAX/100;
	//cout<<"\n\n";
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				v[a[i][j].to-n].push_back((road){a[i][k].to-n,a[i][j].cost+a[i][k].cost});
				v[a[i][k].to-n].push_back((road){a[i][j].to-n,a[i][j].cost+a[i][k].cost});
				//cout<<a[i][k].to-n<<' '<<a[i][j].to-n<<endl;
			}
		}
	}
	//cout<<"\n\n";
	for(int i=1;i<=m;i++)dijkstra(i);
	while(ques--){
		cin>>x>>y;
		ans=LONG_LONG_MAX/100;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				ans=min(ans,the_cost[x]+the_cost[y]+vis[a[x][i].to-n][a[y][j].to-n]+a[x][i].cost+a[y][j].cost);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
