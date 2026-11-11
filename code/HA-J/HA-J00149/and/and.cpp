#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005];
bool vis[200005];
void dfs(int k){
	if(k==m){
		int p=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(p==0)p=a[i];
				else p=p&a[i];
			}
		}
		ans=max(ans,p);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(k-1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	dfs(n);
	printf("%d",ans);
	return 0;
}
