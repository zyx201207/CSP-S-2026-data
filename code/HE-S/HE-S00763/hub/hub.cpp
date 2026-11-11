#include<bits/stdc++.h> 
#define N 15
using namespace std;
const int inf = 1e8;
int T,c,n,k,cnt,ans=inf;
int dis[N][N];
vector<int> g[N];
struct Node{
	int id,fa,chose,from;
};
queue<Node> q;
void solve1(int state){
//	for(int i=n;i>=1;i--){
//		cout<<((state>>i)&1);
//	}cout<<'\n';

	int R=0;
	for(int i=1;i<=n;i++){
		int minn=inf;
		for(int j=1;j<=n;j++){
			if((state>>j)&1){
				minn=min(minn,dis[i][j]);
			}
		}
		R=max(R,minn);
	}
	ans=min(ans,R);
}
void solve(int state,int num){
	if(num!=k) return;cnt=0;
//	for(int i=n;i>=1;i--){
//		cout<<((state>>i)&1);
//	}cout<<'\n';
	int chose1=((state>>1)&1);
	if(chose1) cnt++;
	q.push({1,1,chose1,0});
	while(!q.empty()){
		Node cur=q.front();q.pop();
		int x=cur.id,fa=cur.fa,chosex=cur.chose,from=cur.from;
		for(auto y : g[x]){
			if(y==from) continue;
			int chosey=((state>>y)&1);
			if(chosey==0) q.push({y,y,chosey,x});
			else{
				if(chosex==1) q.push({y,fa,chosey,x});
				else{
					q.push({y,y,chosey,x});
					cnt++;
				} 
			}
		}
	}
	if(cnt==2){
		solve1(state);
	}
}
void dfs(int step,int num,int state){
	step++;
	if(step>n){
		solve(state,num);
		return;
	}
	dfs(step,num,state);
	state|=(1<<step);
	dfs(step,num+1,state);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ans=inf;
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=1;j<=n;j++) dis[i][j]=inf;
		}
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v]=1,dis[v][u]=1;
		}
		for(int i=1;i<=n;i++) dis[i][i]=0;
		for(int p=1;p<=n;p++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
					
//		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout<<i<<" to "<<j<<" is "<<dis[i][j]<<'\n';
		dfs(0,0,0);
		cout<<ans<<'\n'; 
	}
	
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
