#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxn,f[N],x[N];
void dfs(int p){
	if(p==m+1){
		int ans=x[1];
		for(int i=2;i<=m;i++){
			ans&=x[i];
		}
		maxn=max(ans,maxn);
		return;
	}
	for(int i=f[p-1]+1;i<=n;i++){
		f[p]=i;
		x[p]=a[f[p]];
		dfs(p+1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<maxn;
	return 0;
}

