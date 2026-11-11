#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ans[300005];
bool vis[300005];
int idx[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3002;i++){
		vis[i]=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=true;
				idx[a[j]]=j;
			}else{
				for(int k=idx[a[j]];k<j;k++){
					vis[a[k]]=false;
					idx[a[k]]=0;
				}
				idx[a[j]]=j;
				vis[a[j]]=true;
			}
		}
		for(int k=1;k<=m;k++){
				if(vis[k]){
					ans[k]++;
				}
			}
		memset(idx,0,sizeof idx);
		memset(vis,0,sizeof vis);
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
