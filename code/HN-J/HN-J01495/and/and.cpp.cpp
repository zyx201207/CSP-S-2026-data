#include<bits/stdc++.h>
using namespace std;
long long b[200005],n,m,a[200005],maxn=-1;
void dfs(long long c,long long res,long long k){
	if(k>n){
		if(c==m){
			maxn=max(maxn,res);
			return ;
		}
		return ;
	}
	dfs(c,res,k+1);
	dfs(c+1,(res&a[k]),k+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,a[i],i+1);
	}
	cout<<maxn;
	return 0;
}

