#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],vis[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]=i;
	}
	if(n*n*n<=1e8){
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(b,0,sizeof(b));
			for(int j=i;j<=n;j++){
				if(vis[a[j]]>0){
					for(int k=vis[a[j]];k<=j-1;k++){
						vis[a[k]]=0;
					}
				}
				vis[a[j]]=j;
			}
			for(int j=1;j<=m;j++){
				if(vis[j]!=0){
					ans[j]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
	}
	else{
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
	}
	return 0;
}
