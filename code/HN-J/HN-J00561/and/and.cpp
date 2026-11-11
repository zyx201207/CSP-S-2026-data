#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int ans=INT_MIN;
void dfs(int cnt,int idx,int sum){
	if(idx>n){
		if(cnt==m) ans=max(sum,ans);
		return ;
	}
	dfs(cnt+1,idx+1,sum&a[idx]);
	dfs(cnt,idx+1,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,-1);
	cout<<ans<<endl;
	return 0;
}

// 湖南省株洲市第二中学
// Luogu 1226884 1251088
//  No.2 Middle School of Zhuzhou Hunan

// 25 pts ?
