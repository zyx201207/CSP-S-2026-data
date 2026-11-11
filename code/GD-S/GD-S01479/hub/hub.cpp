#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int dis[1010][1010],st,msk;
bool v[N];
vector<int> G[N];
void getdis(int x,int fa){
	dis[st][x]=dis[st][fa]+1;
	for(int y:G[x])if(y!=fa)getdis(y,x);
}
void dfs(int x){
	v[x]=1;
	for(int y:G[x]){
		if(!v[y]&&((msk>>y-1)&1))dfs(y);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _;
	scanf("%d%d",&_,&_);
	while(_--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for(st=1;st<=n;st++)getdis(st,0);
		int ans=2e9;
		for(msk=1;msk<1<<n;msk++){
			if(__builtin_popcount(msk)!=k)continue;
			for(int j=1;j<=n;j++)v[j]=0;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(!v[j]&&((msk>>j-1)&1))cnt++,dfs(j);
			}
			if(cnt>2)continue;
			int mx=0;
			for(int j=1;j<=n;j++){
				if(v[j])continue;
				int mn=2e9;
				for(int k=1;k<=n;k++){
					if(v[k])mn=min(mn,dis[j][k]-1);
				}
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		printf("%d\n",ans);
	}
	return 0;
}
