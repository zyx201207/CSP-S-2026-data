#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,inf=1e18;
int C,T,n,m,ans=inf;
int f[N],dp[N][20],dep[N];
bool fl[N];
vector<int> vec[N];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void get(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int u:vec[x]){
		if(u==fa) continue;
		dp[u][0]=x;
		for(int j=1;j<20;j++) dp[u][j]=dp[dp[u][j-1]][j-1];
		get(u,x);
	}
}
int lca(int x,int y){
	if(x==y) return x;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[dp[x][i]]>=dep[y]) x=dp[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(dp[x][i]!=dp[y][i]) x=dp[x][i],y=dp[y][i];
	}
	return dp[x][0];
}
void dfs(int x){
	if(x==n){
		int rt1=0,rt2=0,res=0,cnt=0;
		vector<int> now;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=n;i++){
			if(fl[i]){
				cnt++;
				for(int u:vec[i]) if(fl[u]){
					if(find(i)!=find(u)) f[find(i)]=f[find(u)];
				}
			}
		}
		if(cnt!=m) return ;
		for(int i=1;i<=n;i++){
			if(fl[i]){
				now.push_back(i);
				int cur=find(i);
				if(!rt1) rt1=cur;
				else if(!rt2&&cur!=rt1) rt2=cur;
				if(cur!=rt1&&cur!=rt2) return ;
			}
		}
		if(!rt1&&!rt2) return ;
//		for(int x:now) cout<<x<<" ";
//		cout<<endl;
		for(int i=1;i<=n;i++){
			if(fl[i]) continue;
			int res1=inf;
			for(int u:now) res1=min(res1,dep[i]+dep[u]-dep[lca(i,u)]*2);
			res=max(res,res1); 
		}
		ans=min(ans,res);
		return ;
	}
	dfs(x+1);
	fl[x+1]=1;
	dfs(x+1);
	fl[x+1]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		get(1,0);
		dfs(0);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) vec[i].clear();
		ans=inf;
	}
	return 0;
}
