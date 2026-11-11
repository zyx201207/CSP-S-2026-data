#include<bits/stdc++.h>
using namespace std;
int a[5000005],nxt[5000005],vis[3000005],ans[3000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			nxt[j]=j+1;
			vis[j]=-1;
		}
		for(int j=n+1;j<=m;j++){
			vis[j]=-1;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=-1){
				nxt[vis[a[j]]]=j+1;
			}else{
				vis[a[j]]=j;
				nxt[j-1]=j;
			}
		}
		int x=i;
		while(x!=n){
			ans[a[x]]++;
			x=nxt[x];
		}
		ans[a[x]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
