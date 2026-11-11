#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1;
void dfs(long long x,long long k,long long tot){
	if(k==m){
		ans=max(ans,tot);
		return;
	}
	if(x>n)return;
	dfs(x+1,k,tot);
	dfs(x+1,k+1,tot&a[x]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		dfs(i+1,1,a[i]);
	}
	cout<<ans;
	return 0;
}
