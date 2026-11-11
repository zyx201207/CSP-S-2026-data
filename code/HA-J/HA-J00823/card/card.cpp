#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005],b[300005],ans[200005],c[200005];
bool zt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			vis[a[j]]=0;
			b[a[j]]=0;
			c[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				for(int k=b[a[j]];k<=a[j];k++){
					c[k]=1;
				}
			}
			b[a[j]]=j;
			vis[a[j]]=1;
		}
		for(int j=i;j<=n;j++){
			if(c[j]==0)ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

