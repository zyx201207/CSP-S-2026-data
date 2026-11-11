#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxx;j++){
			vis[j]=0;
		}
		maxx=0;
		for(int j=i;j<=n;j++){
			maxx=max(maxx,a[j]);
			if(vis[a[j]]==0){
				vis[a[j]]=1;
			}
			else{
				int flag=0;
				for(int k=i;k<j;k++){
					if(flag&&a[k]!=a[j]){
						vis[a[k]]=0;
					}
					if(a[k]==a[j]){
						flag=1;
					}
				}
			}
		}
		for(int j=1;j<=maxx;j++){
			if(vis[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
