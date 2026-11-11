#include<bits/stdc++.h>
using namespace std;
int n,k,c,t,ce[(1 << 16)];
vector<int>e[1000009];
int srh(int x,int fa,int sta){
	if((sta >> (x - 1)) & 1)
		return 0;
	int o = n;
	for(unsigned i = 0; i < e[x].size(); i ++){
		if(e[x][i] != fa)
			o = min(o,srh(e[x][i],x,sta) + 1);
	}
	return o;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i = 1; i <= n; i ++){
			e[i].clear();
		}
		for(int i = 1; i < n; i ++){
			int u,v;
			scanf("%d %d",&u,&v);
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		if(n <= 15){
			int ans = n;
			for(int i = 1; i < (1 << n); i ++){
				int j = i & (-i),s = __builtin_ctz(i) + 1;
				ce[i] = ce[i ^ j];
				for(unsigned l = 0; l < e[s].size(); l ++){
					if((i >> (e[s][l] - 1)) & 1){
						ce[i] ++;
					}
				}
				if(__builtin_popcount(i) == k && ce[i] >= k - 2){
					int p = 0;
					for(int l = 1; l <= n; l ++){
						p = max(p,srh(l,0,i));
					}
					ans = min(ans,p);
				//	printf("%d %d\n",i,p);
				}
			}
			printf("%d\n",ans);
		}
	}
}
