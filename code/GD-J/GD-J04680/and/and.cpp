#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int d[200005],u[200005];
void dfs(int step){
	if(step>m){
		int x=d[1];
		for(int i=2;i<=m;i++){
			x=x&d[i];
		}
		ans=max(ans,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(u[a[i]]==1)continue;
		if(u[a[i]]==0)d[step]=a[i],u[a[i]]=1;
		dfs(step+1);
	    d[step]=0;
	    u[a[i]]=0;
	} 
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
