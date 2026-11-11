#include<bits/stdc++.h>
using namespace std;
const long long N=510;
long long c,n,m,d,q,l,r,T,ans;
long long w[N];
long long adj[N][N];
vector< long long > Maps[N];
bool vis[N],vis1[N];
bool dfs(long long x,long long sum,long long id){
	if(id==r){
		T=sum+w[r];
		ans=min(ans,T);
		return true;
	}
	for(auto i : Maps[x]){
		if(i==id) continue;
		if(vis[i]==true) continue;
		long long P=sum;
		for(long long j=1;j<=n;j++){
			if(adj[j][i]!=0){
				bool I=false;
				if(j!=x){
					vis[i]=true;
					I=dfs(j,P+adj[x][i]+adj[j][i],i);
				}
				else{
					vis[i]=true;
					I=dfs(j,P+adj[j][i],i);
				}
			}
		}
		vis[i]=false;
	}
	return false;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			Maps[i].push_back(a);
			adj[i][a]=t;
		}
	}
	while(q--){
		memset(vis,0,sizeof vis);
		memset(vis,0,sizeof vis1);
		ans=LONG_LONG_MAX;
		T=0;
		cin>>l>>r;
		vis[l]=true;
		for(long long i=1;i<=n;i++){
			T=0;
			if(adj[i][l]!=0){
				if(dfs(i,w[i]+adj[i][l],l)==0) T=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
