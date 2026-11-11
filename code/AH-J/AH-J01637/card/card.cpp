#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],used;
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=used;k<j;j++){
				if(vis[k]==1&&a[k]==a[j]){
					memset(vis,0,sizeof(vis));
					used=k;
					break;
				}
			}
			vis[j]=1;
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
