#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+10;
int c,t,n,d;
int vis[maxn],dis[maxn];
ll x[maxn],ans;
queue <pair<int,int> > q;
void bfs(int s){//zhaochu zuiduan changdu
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({s,0});
	while(!q.empty()){
		pair<int,int> cur=q.front(); 
		q.pop();

		int u=cur.first;
		int d=cur.second;
		//cout<<u<<" "<<d<<"\n";
		//if(x[u+1]-x[u]>d) {continue;}//feibuzou
		
		int i;
		//zhaochu nengdaoda zuiyuan de daoyu
		for(i=u+1;i<=n;i++)
			if(x[i]-x[u]>d)break;
		
		i--;
		//cout<<tmp<<"\n";
		//bianli nengdaoda de daoyu
		for(int k=i;k>u;k--){
			//cout<<i<<"\n";
			if(!vis[k]) {
				//cout<<i<<" "<<d+1<<"\n";
				dis[k]=d+1;
				vis[k]++;}
			else if(d+1==dis[k]){
				vis[k]++;
				//cout<<vis[i]<<"\n";
			}
			q.push({k,d+1});
		}
		
	}
	for(int i=s+1;i<=n;i++){
		if(vis[i]==2) ans++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		//memset(dis+1,dis+n+1,inf);
		for(int i=1;i<=n;i++)
			{
			cin>>x[i];}
		for(int j=1;j<n;j++){
			bfs(j);
		}
		cout<<ans<<"\n";
	}
}
