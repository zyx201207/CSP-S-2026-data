#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=7e5+5,M=505;
int w[N],vis[M][M],mp[M][M];
vector<pair<int,int> > v[N],du[N];
int c,n,m,d,q;
void bfs(int s)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 
	q.push({1,s});
	while(!q.empty()){
		pair<int,int> u=q.top();
		q.pop();
		if(vis[s][u.second])continue;
		vis[s][u.second]=u.first;
		for(int i=1;i<=n;i++){
			if(!vis[s][i]&&mp[i][u.second]!=1e18)
			q.push({u.first+mp[i][u.second],i});
		}
	}
	for(int i=1;i<=n;i++)vis[s][i]-=1;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			du[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto man : du[i]){
			for(auto siu : du[i]){
				if(siu.first==man.first)continue;
				mp[siu.first][man.first]=min(mp[siu.first][man.first],siu.second+man.second);
				mp[man.first][siu.first]=min(mp[man.first][siu.first],siu.second+man.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto man : du[x]){
			for(auto siu : du[y]){
				if(vis[man.first][siu.first]==-1)continue;
				ans=min(ans,vis[man.first][siu.first]+man.second+siu.second+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	} 
 } 
 /*
 0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

 */
