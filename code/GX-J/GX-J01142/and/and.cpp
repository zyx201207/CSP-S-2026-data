#include <bits/stdc++.h>
using namespace std;
long long n,m,mx;
long long a[200010];
void dfs(long long x,long long st,long long sm){
	if(st==m+1){
		mx=max(mx,sm);
		return;
	}
	for(long long i=x+1;i<=n;i++){
		dfs(i,st+1,sm&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,1,(1<<30)-1);
	cout<<mx;
    return 0;
}
