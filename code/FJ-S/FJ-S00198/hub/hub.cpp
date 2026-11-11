#include <bits/stdc++.h>
#define int long long
#define rint register int
#define il inline
#define ms memset
using namespace std;
const int inf=2e18;
int c,t;
int n,k;
vector<int>v[1000005];
int f[1000005][3];
int vis[11];
int ans;
int fa[11];
il int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
il int dfs(int now,int fa){
	int ret=inf;
	if(vis[now]) ret=0;
	for(auto t:v[now]){
		if(t==fa) continue;
		ret=min(ret,dfs(t,now)+1);
	}
	return ret;
}
il void sol(){
	cin>>n>>k;
	for(rint i=1;i<=n;i++){
		v[i].clear();
	}
	for(rint i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}	
	ans=inf;
	for(rint i=0;i<(1<<n);i++){
		int sum=0,maxn=0;
		for(rint j=0;j<n;j++){
			if((i>>j)&1){
				vis[j+1]=1;
				sum++;
			}else{
				vis[j+1]=0;
			}
		}
		if(sum==k){
			for(rint j=1;j<=n;j++){
				fa[j]=j;
			}
			for(rint j=1;j<=n;j++){
				if(vis[j]){
					for(auto t:v[j]){
						if(vis[t]){
							fa[find(j)]=find(t);
						}
					}
				}
			}
			int cnt=0;
			for(rint j=1;j<=n;j++){
				if(vis[j]){
					if(fa[j]==j){
						cnt++;
					}
				}
			}
			if(cnt==2){
				for(rint i=1;i<=n;i++){
					maxn=max(maxn,dfs(i,0));
				}
				ans=min(ans,maxn);
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		sol();
	}	
	return 0;
}
//Away From OI 
