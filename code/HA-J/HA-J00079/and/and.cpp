#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxx=-1,a[200009];
void dfs(int sum,int o,int k){
	if(o==m){
		maxx=max(maxx,sum);
		return;
	}
	for(int i=k+1;i<=n;i++){
		dfs(sum&a[i],o+1,i);
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
	cout<<maxx;
	return 0;
}
