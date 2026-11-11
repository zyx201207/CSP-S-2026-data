#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000+5;
int c,t,n,d,x[N*N*3];
vector<int>g[N];
int dis[N][N],path[N][N],ans;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
void dijkstra(int s){
	dis[s][s]=0;
	path[s][s]=1;
	pq.push({0,s});
	while(pq.size()){
		pair<int,int>now=pq.top();
		pq.pop();
		int u=now.second,w=now.first;
		if(dis[s][u]<w)continue;
		for(auto v: g[u]){
			if(dis[s][v]>w+1){
				dis[s][v]=w+1;
				pq.push({w+1,v});
				path[s][v]=path[s][u];
			}else if(dis[s][v]==w+1){
				path[s][v]+=path[s][u];
				if(path[s][v]>2)path[s][v]=3;
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if((c==11)||(c==12)){
		int f=d/(x[2]-x[1]),ans=0;
		if(f>1){
			f=2*f-1;
			ans=max(ans,n-f);
		}
		cout<<ans<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d)g[i].push_back(j);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	memset(path,0,sizeof(path)); 
	ans=0;
	for(int i=1;i<=n;i++)dijkstra(i);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=(path[i][j]==2);
		}
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)g[i].clear();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve(); 
}
/*
32
*/
