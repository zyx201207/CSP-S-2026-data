#include<bits/stdc++.h>
using namespace std;
long long a[200005],cnt=0;
int m,n;
void dfs(int last,int st,long long ans) {
	if(st==m+1) {
		cnt=max(cnt,ans);
		return ;
	} 
	if(n-last+st<m) return ;
	for(int i=last+1;i<=n;i++) {
		if(st==1) dfs(i,st+1,a[i]);
		else dfs(i,st+1,ans&a[i]);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	dfs(0,1,0);
	cout<<cnt;
	return 0;
}
