#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn,b;
void dfs(long long s,long long x){
	if(x==m){
		maxn=max(maxn,a[s]&a[s-1]);
		return;
	}
	dfs(s,x+1);
	dfs(s+1,x+1);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<maxn;
	return 0;
}
