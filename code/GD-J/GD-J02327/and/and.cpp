#include <bits/stdc++.h>

int n,m;
int a[200001];
int b[200001];
int ans;

void dfs(int idx,int cnt){
	b[cnt]=a[idx];
	if (cnt==m){
		int ans1=b[1];
		for (int i=2;i<=m;i++) ans1&=b[i];
		ans=std::max(ans,ans1);
		b[cnt]=0;
		return;
	}
	for (int i=idx+1;i+m-cnt-1<=n;i++) dfs(i,cnt+1);
	b[cnt]=0;
}

int main(){
	std::freopen("and.in","r",stdin);
	std::freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n>>m;
	for (int i=1;i<=n;i++) std::cin>>a[i];
	dfs(0,0);
	std::cout<<ans<<std::endl;
	return 0;
}

