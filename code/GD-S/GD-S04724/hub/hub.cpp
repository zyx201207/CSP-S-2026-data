#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX/5;
struct bcj{
	vector<int> par,cnt;
	int n;
	bcj(int a):n(a),par(a+1),cnt(a+1,1){
		for(int i=1;i<=n;i++) par[i]=i;
	}
	int search(int x){
		if(par[x]!=x) par[x]=search(par[x]);
		return par[x];
	}
	void merge(int x,int y){
		int rx=search(x),ry=search(y);
		if(rx==ry) return;
		if(cnt[rx]>cnt[ry]) swap(rx,ry);
		par[rx]=ry;
		cnt[ry]+=cnt[rx];
	}
};
void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> g(n+1);
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	vector<bool> lis(n+1);
	vector<int> dis(n+1);
	int ans=INT_MAX;
	function<void(int,int)> dfs;
	dfs=[&](int x,int c)->void{
		if(x==n && c==k){
			bcj ji(n);
			for(int i=1;i<=n;i++)
				if(lis[i])
					for(auto j:g[i])
						if(lis[j]) ji.merge(i,j);
			int p1=-1,p2=-1;
			for(int i=1;i<=n;i++)
				if(lis[i]){	
					int	ri=ji.search(i);		
					if(p1==-1) p1=ri;
					else if(p1!=ri){
						if(p2==-1) p2=ri;
						else if(p2!=ri) return;
					}
				}
			int sum=0;
			queue<int> q;
			for(int i=1;i<=n;i++)
				if(lis[i]){
					dis[i]=0;
					q.emplace(i);
				}
				else dis[i]=inf;
			while(q.size()){
				int u=q.front();
				q.pop();
				sum=max(sum,dis[u]);
				for(auto v:g[u])
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.emplace(v);
					}
			}
			ans=min(ans,sum);
			//cout<<sum<<" ";
			//for(int i=1;i<=n;i++) cout<<(int)(lis[i])<<" ";
			//cout<<'\n'; 
			return;
		}
		if(n-x<k-c || (x==n &&c!=k) || (x!=n && c==k)) return;
		if(c<k){
			lis[x+1]=1;
			dfs(x+1,c+1);
		}
		if(n-x>k-c){
			lis[x+1]=0;
			dfs(x+1,c);
		}
	};
	dfs(0,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t>>t;
	while(t--) solve();
	return 0;
} 
