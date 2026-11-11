#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
void dfs(int x,int an,int cnt){
	if(an<=ans)return;
	if(x>n||cnt==m){
		ans=max(an,ans);
		return;
	}
	dfs(x+1,an&a[x],cnt+1);
	if(n-x>=m-cnt)dfs(x+1,an,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,2147483647,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
