#include<bits/stdc++.h>
using namespace std;
int n;
int f[20005][20005],a[200002];
char c[200002];
int dfs(int l,int r){
	if(l>=r)return 0;
	if(f[l][r]!=-1)return f[l][r];
	f[l][r]=2e9;
	if(c[l]==c[r])
		f[l][r]=dfs(l+1,r-1);
	f[l][r]=min(f[l][r],dfs(l+1,r-1)+max(a[l],a[r]));
//	cout<<l<<' '<<r<<' '<<f[l][r]<<'\n';
	return f[l][r];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		for(int j=1;j<=n;++j)f[i][j]=-1ll;
		if(c[i]==c[i+1])f[i][i+1]=0;
		else f[i][i+1]=min(a[i],a[i+1]);
	}f[0][1]=-1;
	cout<<dfs(1,n);
	return 0;
}
