#include <bits/stdc++.h>
using namespace std;
int a[300005];
int ans[300005];


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int idx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=m;i++){
		int vis[300005];
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			vis[a[j]]++;
			if(vis[a[j]]==2){
				for(int k=i;k<=j;k++){
					vis[k]=0;
				}
				vis[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
