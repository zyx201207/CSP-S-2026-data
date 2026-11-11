#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int> 
using namespace std;
const int N=2010;

struct node{
	int x,y;
}; 

int c,n,m,d,q,ks,js;
int a[N][N],t[N][N],w[N];
int dis[N];
bool v[N];
vector<node> e[N];
vector<node> o[N];
int ee[N][N];

void dj(){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,ks});
	dis[ks]=0;
	while(!q.empty()){
		pii t=q.top();
		q.pop();
		for(node p:o[t.second]){
			int u=p.x,v=p.y;
			if(dis[u]>dis[t.second]+ee[t.second][u]){
				dis[u]=dis[t.second]+ee[t.second][u];
				q.push({dis[u],u});
				//cout<<dis[u]<<endl;
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,te;i<=n;i++){
		cin>>te;
		for(int j=1,x,y;j<=te;j++){
			cin>>x>>y;
			//cout<<x<<" "<<y<<endl;
			e[i].push_back({x,y});
			//cout<<e[1][0].x<<endl;
			//cout<<11111;
			ee[i][x]=y;
			ee[x][i]=y;
		} 
	}
	//cout<<e[1][0].x<<' '<<e[1][0].y<<endl;
	for(int i=1;i<=n;i++){
		//cout<<e[1][1].x<<endl;
		for(node p:e[i]){
			for(node t:e[i]){
				//cout<<p.x<<" "<<t.x<<endl;
				if(p.x==t.x) continue;
				o[p.x].push_back({t.x,ee[p.x][i]+ee[t.x][i]});
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(node t:o[i]){
			ee[i][t.x]=t.y;
			ee[t.x][i]=t.y;
			//cout<<i<<' '<<t.x<<' '<<t.y<<endl; 
		}
	}
	while(q--){
		cin>>ks>>js;
		dj();
		cout<<dis[js]+w[ks]+w[js]<<endl;
	}
	return 0;
}
