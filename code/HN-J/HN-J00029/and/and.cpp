#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m,ans,b[100005],vis[100005];
void dfs(int step){
	if(step==m){
		int v;
		for(int i=1;i<=step;i++){
			if(i==1)v=b[i];
			else v&=b[i];
		}
		ans=max(ans,v);
	}
	else {
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				b[step+1]=a[i];
				vis[i]=1;
				dfs(step+1);
				b[step+1]=0;
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
