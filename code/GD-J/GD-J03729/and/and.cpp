#include <bits/stdc++.h>
using namespace std;
int a[20005],n,m,ans;
void dfs(int x,int sum,int cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=x+1;i<=n-m+cnt+1;i++){
		dfs(i,sum&a[i],cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,-1,0);
	cout<<ans;
	return 0;
}

