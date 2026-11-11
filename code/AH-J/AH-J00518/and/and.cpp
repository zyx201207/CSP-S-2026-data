#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxn;
int a[200010];
bool f[200010];
void dfs(int t,int k){
	if(t==m){
		maxn=max(maxn,k);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		dfs(t+1,k&a[i]);
		f[i]=0;
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		dfs(1,a[i]);
		f[i]=0;
	}
	cout<<maxn;
	return 0;
}//20
