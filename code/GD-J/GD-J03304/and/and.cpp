#include<cstdio>
using namespace std;
typedef long long ll;
int m,n,sz[200005],a[200005];
bool vis[200005]={};
ll ans=-1;
ll max(ll a,ll b){
	return (a>b?a:b);
}
void dfs(int cnt,int nowi){
	if(cnt==m){
		int t=a[0];
		for(int i=1;i<m;i++)t&=a[i];
		ans=max(ans,t);
	}
	for(int i=nowi;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		a[cnt]=sz[i];
		dfs(cnt+1,i);
		vis[i]=false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&sz[i]);
	dfs(0,1);
	printf("%lld",ans);
	return 0;
} 
