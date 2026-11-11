#include <iostream>
#include <vector>
#include <queue>
const int inf=1e18;
const int maxn=2e6+32;
long long x[maxn];
std::vector<std::pair<int,int>> G[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int c,t;
	std::cin>>c>>t;
	while(t--){
		long long n,d;
		std::cin>>n>>d;
		for(int i=1;i<=n;i++){
			std::cin>>x[i];
			G[i].clear();
		}
		if(x[n]-x[1]<=d){
			std::cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) G[i].push_back({j,1});
				else break;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			std::vector<long long> d(n+1,inf),cnt(n+1);
			d[i]=0;
			std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q;
			q.push({0,i});
			cnt[i]=1;
			while(!q.empty()){
				int u=q.top().second;
				int w=q.top().first;
				q.pop();
				if(w>d[u]) continue;
				for(auto e:G[u]){
					int v=e.first;
					int ww=e.second;
					if(d[v]>d[u]+ww){
						d[v]=d[u]+ww;
						cnt[v]=cnt[u];
						q.push({d[v],v});
					}else if(d[v]==d[u]+ww){
						cnt[v]+=cnt[u];
					} 
				}
			}
			for(int i=1;i<=n;i++){
				if(cnt[i]==2) ans++;
			}
		}
		std::cout<<ans<<'\n';
	}
	return 0;
}
