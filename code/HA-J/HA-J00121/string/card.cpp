#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[100001],vis[100001],ans[100001];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i]; 
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++) vis[i]=0;
		for(int j=i;j<=n;j++) a[i]=b[i];
		for(int j=i;j<=n;j++){
			for(int z=1;z<j;z++) if(a[j]==a[z]){
				for(int t=1;t<z;t++) a[t]=0;
			}
		}
		for(int j=i;j<=n;j++) if(a[j]>0&&vis[a[j]]==0) ans[a[j]]++,vis[a[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}


