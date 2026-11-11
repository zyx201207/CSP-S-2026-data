#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e2+5;
const int M=210*400;
int C,n,m,d,qq,ans;
int vis[M],dp[M];
struct node{
	int x,w;
};
bool operator <(const node &x,const node &y){
	return x.w>y.w;
}
vector<node> a[M];
void add(int x,int y,int w);
int get(int x,int y);
int dij(int st,int ed);
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		add(get(i,0),get(i,1),x);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last=-1;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			add(get(x,1),get(x,i+1),y);
			if(last!=-1) add(get(x,i+1),get(last,i+1),0);
			last=x;
		}
	}
	while(qq--){
		int u,v;
		cin>>u>>v;
		cout<<dij(u,v)<<'\n';
	}
	return 0;
} 
void add(int x,int y,int w){
	a[x].push_back({y,w});
	a[y].push_back({x,w}); 
	return ;
}
int get(int x,int y){
	return x+y*m;
}
int dij(int st,int ed){
	memset(dp,0x3f,sizeof(dp));
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({st,0});
	while(!q.empty()){
		int x=q.top().x;
		int w=q.top().w;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		dp[x]=w;
		for(int i=0;i<a[x].size();i++){
			int to=a[x][i].x;
			if(dp[to]>w+a[x][i].w){
				q.push({to,a[x][i].w+w});
			}
		}
	}
	return dp[ed];
}
