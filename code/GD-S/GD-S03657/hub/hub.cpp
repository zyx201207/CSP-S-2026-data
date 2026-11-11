#include<bits/stdc++.h>
using namespace std;
using i64=long long;
using u64=unsigned long long;
using u32=unsigned;
const int N=1e6+5;
int Cid,n,k,mark[N],vis[N];
vector<int>G[N];
void dfs(int u){
	vis[u]=1;
	for(int v:G[u]){
		if(mark[v]&&!vis[v]){
			dfs(v);
		}
	}
}
int Main(){
	cin>>n>>k;
	int ans=n;
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int S=0;S<1<<(n+1);S+=2){
		if(__builtin_popcount(S)!=k)continue;
		for(int i=1;i<=n;++i){
			mark[i]=S>>i&1;
			vis[i]=0;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(mark[i]&&!vis[i]){
				dfs(i);
				++cnt;
			}
		}
		if(cnt<=2){
			for(int i=1;i<=n;++i){
				vis[i]=0;
			}
			queue<pair<int,int>>q;
			for(int i=1;i<=n;++i){
				if(mark[i]){
					q.emplace(i,0);
					vis[i]=1;
				}
			}
			int res=0;
			for(;q.size();q.pop()){
				auto[u,f]=q.front();
				res=max(res,f);
				for(int v:G[u]){
					if(!vis[v]){
						vis[v]=1;
						q.emplace(v,f+1);
					}
				}
			}
			ans=min(ans,res);
		}
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	for(cin>>Cid>>t;t--;){
		cout<<Main()<<'\n';
		for(int i=1;i<=n;++i){
			G[i].clear();
		}
	}
}