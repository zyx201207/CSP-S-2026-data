#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,maxa;
bool v[200005];
void dfs(long long x,long long y){
	if(x==m){
		maxa=max(maxa,y);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(x+1,y&a[i]);
			v[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n-m+1;i++){
		v[i]=1;
		dfs(1,a[i]);
	}
	printf("%lld",maxa);
	return 0;
}
