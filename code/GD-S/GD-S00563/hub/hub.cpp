#include<bits/stdc++.h>
#define ll long long
#define love_Elysia return
#define forever 0
using namespace std;
const int N=1e6+10;
int c,t,n,k;
vector<int>g[N+1];
bool jd[N+1],vis[N+1];
queue<pair<int,int> >q;
void dfs(int u){
//	if(cs==262)cout<<u<<endl;
	vis[u]=true;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]||(!jd[v]))continue;
		dfs(v);
	}
}
int bfs(int s){
	while(!q.empty())q.pop();
	q.push(make_pair(s,0));
	for(int i=1;i<=n;i++)vis[i]=false;
	vis[s]=true;
	int ans1;
	while(!q.empty()){
		int u=q.front().first;
		int step=q.front().second;
		q.pop();		
		if(jd[u]){
			ans1=step;
			break;
		}
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(vis[v])continue;
			vis[v]=true;
			q.push(make_pair(v,step+1));
		}
	}
	return ans1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans=1e7;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=1;j<=n;j++)jd[j]=false,vis[j]=false;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					cnt++;
					jd[j+1]=true;
				}
			}
			if(cnt!=k)continue;
			int ltk=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&jd[j]){
					ltk++;
					dfs(j);
				}
			}
			if(ltk>2)continue;
			int ans1=0;
			for(int j=1;j<=n;j++){
				ans1=max(ans1,bfs(j));
			}
			ans=min(ans1,ans);
//			if(ans1==2){
//				for(int j=1;j<=n;j++)if(jd[j])cout<<j<<' ';
//				cout<<endl;
//			}
		}
		cout<<ans<<'\n';
	}
	
	love_Elysia forever;
} 
