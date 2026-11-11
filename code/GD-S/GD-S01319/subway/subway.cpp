#include <iostream>
#include <vector>
#include <queue>

const int MAXM=5e5+10;

std::vector<std::pair<int,long long>>G[MAXM<<2];

int c,n,m,d,q;

std::vector<std::vector<long long>>dis(2010,std::vector<long long>(2010));

#define Re return
#define re Re 0

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=m;++i){
		long long w;
		scanf("%lld",&w);
		
		G[i].push_back({m+i,w});
		G[m+i].push_back({i,w});
	}
	
	int last=0;
	
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		
		int deg=0;
		
		for(int j=1;j<=k;++j){
			int a;
			long long w;
			scanf("%d%lld",&a,&w);
			
			if(deg!=0){
				int Ndeg=m*2+j+last;
				G[deg].push_back({Ndeg,0});
				G[Ndeg].push_back({deg,0});
			}
			
			deg=m*2+j+last;
			G[m+a].push_back({deg,w});
			G[deg].push_back({m+a,w});
		}
		last+=k;
	}
	
	auto dij=[&](int x)->void{
		std::priority_queue<std::pair<int,long long>>q;
		q.push({x,0});
		std::vector<bool>vis(m<<3);
		std::vector<long long>DDD(30000,LLONG_MAX);
		DDD[x]=0;
		
		while(!q.empty()){
			auto tmp=q.top();
			q.pop();
			int u=tmp.first;
			
			if(!vis[u]){
				vis[u]=true;
				
				for(auto Tmp:G[u]){
					int v=Tmp.first;
					long long w=Tmp.second;
					
					if(DDD[v]>DDD[u]+w){
						DDD[v]=DDD[u]+w;
						q.push({v,w});
					}
				}
			}
		}
		
		for(int i=1;i<=m;++i)dis[x][i]=DDD[i];
	};
	
	for(int i=1;i<=m;++i)
		dij(i);
		
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		
		printf("%lld\n",dis[x][y]);		
	}
	
	return 0;
}

/*
Input
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

Input
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
