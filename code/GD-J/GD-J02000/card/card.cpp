#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		bool vis[300005]={};
		int x=i;
		for(int j=i;j<=n;j++){
			f[a[j]]++;
			if(vis[a[j]]==1){
				for(int k=j-1;k>=x;k--){
					f[a[k]]--;
					vis[a[k]]=0;
				}
				x=j;
			}
			vis[a[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",f[i]);
	}
	return 0;
}
