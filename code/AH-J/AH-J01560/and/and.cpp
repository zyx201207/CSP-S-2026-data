#include<bits/stdc++.h>
using namespace std;
int a[200010];
int n,m;
int ans;
void dfs(int step,int cnt,int sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(step>n){
		return;
	}
	for(int i=step+1;i<=n;i++){
		if(cnt==0) dfs(i,cnt+1,a[i]);
		else dfs(i,cnt+1,sum&a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and,out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
