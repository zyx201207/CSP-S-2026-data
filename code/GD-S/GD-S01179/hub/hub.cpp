#include<iostream>
#include<algorithm>
#include<vector>

constexpr int maxn=1e6+7;


std::vector<int>E[maxn];

int dep[maxn],sdmx[maxn];
void dfs1(int u,int fa)
{
	sdmx[u]=dep[u];
	for(auto v:E[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs1(v,u);
		sdmx[u]=std::max(sdmx[u],dep[v]);
	}
}

void dfs2(int u,int fa)
{
	
}

void solve()
{
	int N,K;std::cin>>N>>K;
	for(int i=1;i<N;i++){
		int u,v;std::cin>>u>>v;
		E[u].push_back(v);
		E[v].push_back(u);  
	}
	
	if(N==K){puts("0");return;}
	
	dfs1(1,1);
	puts("0");
}

int main()
{
	
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	int C,T;std::cin>>C>>T;
	while(T--) solve();
	
	return 0;
}
