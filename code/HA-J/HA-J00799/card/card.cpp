#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],vis[N],lim[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(lim,0,sizeof(lim));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				for(int k=vis[a[j]];k<j;k++){
					lim[k]++;
					vis[a[k]]=0;
				}
				vis[a[j]]=j;
			}
			else vis[a[j]]=j;
		}
		for(int k=i;k<=n;k++){
			if(lim[k]==0){
				ans[a[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
