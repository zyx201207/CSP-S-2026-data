#include<bits/stdc++.h>
using namespace std;
int maxx=-2e9,m,n,a[200005];
void dfs(int ans,int sum,int jj){
	if(ans==m){
		maxx=max(maxx,sum);
		return ;
	}
	if(jj>n){
		return ;
	}
	for(int i=jj;i<=n;i++){
		if(sum==0&&jj==1&&ans==0){
			dfs(ans+1,a[i],i+1);
		}else{
			dfs(ans+1,sum&a[i],i+1);
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
	dfs(0,0,1);
	cout<<maxx;
	return 0;
}
