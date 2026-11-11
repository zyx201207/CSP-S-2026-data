#include <bits/stdc++.h>
using namespace std;
long long a[200009],ma=-29103,n,m;
void dfs(long long s,long long jg,long long x){
	if(s==m){
		ma=max(jg,ma);
		return ;
	}
	for(int i=x+1;i<=n;i++){
		dfs(s+1,jg&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,a[i],i);
	}
	cout<<ma<<" ";
}
