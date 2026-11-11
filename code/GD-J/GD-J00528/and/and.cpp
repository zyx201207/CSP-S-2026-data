#include<cstdio>
#define N 200005
int a[N],ans=0,n,m;
bool vis[N];
void dfs(int now,int k){
	if(k==m){
		ans=(ans>now?ans:now);
		return;
	}
	for(int i=0;i<n;++i){
		if(vis[i])continue;
		vis[i]=1;
		dfs(now&a[i],k+1);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<n;++i){
		vis[i]=1;
		dfs(a[i],1);
		vis[i]=0;
	}
	printf("%d",ans);
	return 0;
}
