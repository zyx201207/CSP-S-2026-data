#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+5,inf=1e17;
int c,n,m,d,p;
int w[N],k[N],dp[505][505],vis[N],id[N],tri,ok[N];
struct node{
	int x,ti;
};
vector<node>a[N]; 
struct rod{
	int x,step;
	bool operator < (const rod& f)const{
		return f.step<step;
	}
};
priority_queue<rod>q;
void bfs(int xx){
	tri++;
	for(int i=1;i<=n;i++){
		dp[xx][i]=inf;
		if(dp[i][xx]){
			id[i+m]=tri;
			vis[i+m]=dp[i][xx];
			q.push({xx+m,dp[i][xx]});
		}
	}
	q.push({xx+m,0});
	vis[xx+m]=0,id[xx+m]=tri;
	while(q.size()){
		int x=q.top().x,step=q.top().step;
		q.pop();	
		for(int i=0;i<a[x].size();i++){
			if(id[a[x][i].x]!=tri){
				id[a[x][i].x]=tri;
				vis[a[x][i].x]=inf;
			}
			
			if(step+a[x][i].ti<vis[a[x][i].x]){
				vis[a[x][i].x]=step+a[x][i].ti;
				q.push({a[x][i].x,step+a[x][i].ti});
			}
		}
	}
	for(int i=1;i<=n;i++){
		//cout<<xx<<" "<<i<<" "<<vis[i+m]<<"\n";
		dp[xx][i]=vis[i+m];
	}
	ok[xx]++;
	dp[xx][xx]=0;
}
queue<rod>qq;
void bfs1(int xx){
	tri++;
	for(int i=1;i<=n;i++)dp[xx][i]=inf;
	qq.push({xx+m,0});
	vis[xx+m]=0,id[xx+m]=tri;
	while(qq.size()){
		int x=qq.front().x,step=qq.front().step;
		qq.pop();	
		for(int i=0;i<a[x].size();i++){
			if(id[a[x][i].x]!=tri){
				id[a[x][i].x]=tri;
				vis[a[x][i].x]=inf;
			}
			
			if(step+a[x][i].ti<vis[a[x][i].x]){
				vis[a[x][i].x]=step+a[x][i].ti;
				qq.push({a[x][i].x,step+a[x][i].ti});
			}
		}
	}
	for(int i=1;i<=n;i++){
		//cout<<xx<<" "<<i<<" "<<vis[i+m]<<"\n";
		dp[xx][i]=vis[i+m];
	}
	ok[xx]++;
	dp[xx][xx]=0;
}
struct nas{
	int x,ti;
};
vector<nas>s[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>w[i];//ÂÔ 
	for(int i=1;i<=n;i++){
		cin>>k[i];//Ïß 
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			s[x].push_back({i,y});
			//a[i+m].push_back({x,y});
			//a[x].push_back({i+m,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<s[i].size();x++){
			for(int y=0;y<s[i].size();y++){
				if(x==y)continue;
				a[s[i][x].x+m].push_back({s[i][y].x+m,s[i][x].ti+s[i][y].ti});
				a[s[i][y].x+m].push_back({s[i][x].x+m,s[i][x].ti+s[i][y].ti});
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	//cout<<c<<"\n";
	while(p--){
		int x,y,mi=inf;
		cin>>x>>y;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				//cout<<w[x]+w[y]<<" "<<s[x][i].x<<" "<<s[y][i].x<<" "<<dp[1][2]<<"\n";
				mi=min(w[x]+w[y]+dp[s[x][i].x][s[y][j].x]+s[x][i].ti+s[y][j].ti,mi);
			}
		}
		cout<<mi<<"\n";
	}
	return 0;
}

