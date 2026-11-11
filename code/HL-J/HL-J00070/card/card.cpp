#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int p[10010];
int t[10010];
int ans[10010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[10010];
		for(int j=i;j<=m;j++){
			if(vis[p[i]]==0){
				t[j]=p[i];
				vis[p[i]]=1;
			}
			else{
				for(int k=j+1;k<=m;k++){
					t[k]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(t[j]=i){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}