#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[500010];
int vis[500010],dis[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		vis[i]=dis[a[i]];
		dis[a[i]]=i;
	}for(int begin=1;begin<=n;begin++){
		for(int i=begin;i<=n;i++){
			if(vis[i]==0){
				ans[a[i]]++;
			}
			else i=vis[i]-1;
		}
	}for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
