#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
int cnt[24];
void dfs(int sum,int cnt,int last){
	if(cnt==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=last+1;i<=n;i++){
		dfs(sum&a[i],cnt+1,i);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],1,i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
