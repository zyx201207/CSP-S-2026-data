#include<bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long RP=ULONG_LONG_MAX;
int ceshi,t,n,k,dis[20][20];
vector<int> g[20];
bool vis[20];
void dfs(int u,int f,int s){
	vis[u]=1;
	for(auto v:g[u]){
		if(v!=f&&(s&(1<<(v-1)))) dfs(v,u,s);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>ceshi>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			queue<int> q;
			q.push(i);
			memset(dis[i],0x3f,sizeof(dis[i]));
			dis[i][i]=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:g[u]){
					if(dis[i][v]>dis[i][u]+1){
						dis[i][v]=dis[i][u]+1;
						q.push(v);
					}
				}
			}
		}
		int ans=1e9;
		for(int s=0;s<(1<<n);s++){
			int ppc=0;
			for(int i=s;i;i=i&(i-1)) ppc++;
			if(ppc!=k) continue;
			memset(vis,0,sizeof(vis));
			int cnt=0;
			for(int i=1;i<=n;i++){
				if((s&(1<<(i-1)))&&!vis[i]){
					dfs(i,i,s);
					cnt++;
				}
			}
			if(cnt!=2) continue;
			int res=0;
			for(int i=1;i<=n;i++){
				int t=1e9;
				for(int j=1;j<=n;j++){
					if(s&(1<<(j-1))) t=min(t,dis[i][j]);
				}
				res=max(res,t);
			}
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅∅
/*
0 1
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
