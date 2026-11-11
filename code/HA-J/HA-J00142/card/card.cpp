#include<bits/stdc++.h>
using namespace std;
int n,m,vis[500005],a[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(vis[j]){
				for(int k=vis[j];k<=n;k++){
					vis[a[k]]=0;
				}
				vis[a[j]]=j;
			}
			else vis[a[j]]=j;
		}
		for(int i=1;i<=m;i++){
			if(vis[i]!=0)cnt[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	
	
	return 0;
}
