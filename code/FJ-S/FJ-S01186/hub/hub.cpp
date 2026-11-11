#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
vector<int> v[N];
int n,k;
int vis[N],c[N];
int bfs(int s){
	queue<pair<int,int> > q;
	q.push({s,0});
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		if(vis[u.first])continue;
		vis[u.first]=1;
		if(c[u.first]==1){
			return u.second;
		}
		for(auto man : v[u.first]){
			q.push({man,u.second+1});
		}
	} 
}
int ans=1e18;
void dfs(int x){
	if(vis[x]||c[x]==0)return ;
	vis[x]=1;
	for(auto man : v[x]){
		dfs(man);
	} 
}
void calc(int x,int cnt){
	if(x==n+1){
		if(cnt!=k)return ;
		int res=0,cnt=0;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++){
			if(c[i]&&!vis[i]){
				cnt++,dfs(i); 
			}
		}
		if(cnt>2)return ;
		for(int i=1;i<=n;i++){
			res=max(res,bfs(i)); 
			//cout<<"CH "<<c[i]<<" "<<bfs(i)<<" ";
		} 
		//cout<<"\n"<<res<<'\n';
		ans=min(ans,res);
		return ;
	} 
	c[x]=0;
	calc(x+1,cnt);
	c[x]=1;
	calc(x+1,cnt+1);
} 
void solve()
{
	ans=1e18;
	cin>>n>>k;
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	calc(1,0); 
	cout<<ans<<"\n";
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int c,_;
	cin>>c>>_;
	while(_--){
		solve();
	}
 } 
