#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[3010];
bool vis[3010];
int v[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		int k=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
				v[k]=a[j];
				k++;
			}else{
				while(v[k-1]!=a[j]){
					vis[v[k-1]]=0;
					k--;
				}
			}
		}
		for(int j=0;j<k;j++){
			ans[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
