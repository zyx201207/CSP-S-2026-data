#include<bits/stdc++.h>
using namespace std;
int ans[10000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10000001]={};
	int vis[10000001]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=s;k++){
				if(vis[k]==a[j]){
					for(int z=k;z<=s;z++) vis[z]=0;
					vis[k]=a[j];
				}
				else vis[k]=a[j];
			}
		}
		for(int x=1;x<=m;x++){
			for(int y=1;y<=n;y++){
				if(vis[y]==x) ans[x]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}


