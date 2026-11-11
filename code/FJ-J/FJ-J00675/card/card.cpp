#include <bits/stdc++.h>
using namespace std;
long long n,m,a[111111],b[111111],vis[111111][5],ti,ans[111111],vs[111111],t[111111];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000&&m>=3000){
		int p;
		for(int i=1;i<=n;i++){
			if(a[i-1]>a[i]){
				p=1;
			}
		}
		if(p==0){
			int pi[111111];
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					pi[a[j]]=1;
				}
				for(int j=1;j<=n;j++){
					ans[j]+=pi[j];
					pi[j]=0;
				}
			}
			for(int i=1;i<=m;i++){
				cout<<ans[i]<<' ';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ti++;
			b[ti]=a[j];
			if(vis[a[j]][1]==1){
				ti=vis[a[j]][2];
				vis[a[j]][1]==0;
			}
			else{
				vis[a[j]][1]=1;
				vis[a[j]][2]=ti;
			}
		}
		for(int j=1;j<=ti;j++){
			vs[b[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=vs[j];
			vs[j]=0;
			vis[j][1]=0;
		}
		ti=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	
	return 0;
}
