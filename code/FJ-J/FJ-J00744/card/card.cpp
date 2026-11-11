#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int vis[500005],ans[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				for(int k=vis[a[j]];k<j;k++){
					vis[a[k]]=0;
				}
				vis[a[j]]=j;
			}else{
				vis[a[j]]=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(vis[j]!=0){
				ans[j]++;
				vis[j]=0;
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
