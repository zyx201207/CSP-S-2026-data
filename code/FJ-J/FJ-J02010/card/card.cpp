#include<bits/stdc++.h>
using namespace std;
int n,m,vis[300005],d[500005],ans[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int z=1;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			int f=vis[a[j]];
			if(f){
				for(int k=f+1;k<z;k++)
					vis[d[k]]=0;
				z=f;
			}
			vis[a[j]]=z;
			d[z]=a[j];
			z++;
		}
		for(int j=1;j<z;j++)
			ans[d[j]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
