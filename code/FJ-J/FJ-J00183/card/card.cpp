#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],ans[500100];
bool vis[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
	}for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=i;j>=1;j--){
			if(vis[j]==0){
				vis[j]=1;
				ans[vis[j]]++;
			}else{
				for(int k=i;k>=j;k--) vis[k]=0;
				for(int k=1;k<=m;k++) ans[vis[k]]++;
			}
		}
	}for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
