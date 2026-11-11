#include<bits/stdc++.h>
using namespace std;
int n,m;
int h[200010];
int ans=-1;
void dfs(int cnt,int now,int num) {
	for(int i=now+1; i<=n; i++) {
		if(cnt!=1)dfs(cnt-1,i,int(num&h[i]));
		else ans=max(ans,int(num&h[i]));
	}
	return ;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1; i<=n; i++) {
		cin >>h[i];
	}
	sort(h+1,h+1+n);
	for(int i=1; i<=n-m+1; i++) {
		dfs(m-1,i,h[i]);
	}
	cout <<ans;
	return 0;
}

