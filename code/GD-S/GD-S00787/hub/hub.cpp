#include <bits/stdc++.h>
using namespace std;
int C,t,n,k,ans,c[1001000],dist[1001000];
vector<int>edges[1001000];
inline void solve(int x){
	for(auto y:edges[x])if(dist[y]>dist[x]+1)dist[y]=dist[x]+1,solve(y);
}
inline void dfs(int x){
	if(x==n+1){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=c[i];
		if(sum!=k)return ;
		sum=0;
		for(int i=1;i<=n;i++)
			if(c[i]==1){
				int cnt=0;
				for(auto y:edges[i])cnt+=c[y];
				if(cnt==0)sum++;
			}
		if(sum>=3||(sum==2&&k!=2))return ;
		for(int i=1;i<=n;i++)dist[i]=1e9;
		for(int i=1;i<=n;i++){
			if(c[i]==1){
				dist[i]=0;
				solve(i);
			}
		}
		int ma=0;
		for(int i=1;i<=n;i++)ma=max(ma,dist[i]);
		ans=min(ans,ma);return ;
	}
	c[x]=0,dfs(x+1);
	c[x]=1,dfs(x+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&t);
	if(C<=3){//15pts
		while(t--){
			ans=1e9,scanf("%d%d",&n,&k);
			for(int i=1;i<=n;i++)edges[i].clear();
			for(int i=1,x,y;i<n;i++){
				scanf("%d%d",&x,&y);
				edges[x].push_back(y);
				edges[y].push_back(x);
			}
			dfs(1);
			printf("%d\n",ans);
		}
		return 0;
	}
}
