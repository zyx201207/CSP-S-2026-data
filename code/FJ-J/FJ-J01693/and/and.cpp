#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000001],p[100000001],jy[10000001];
long long dfs(long long d,long long z,long long c){
	if(c==0){
		return z;
	}
	else if(d==n+1){
		return 0;
	}
	long long s,q;
	if(z&&c==m){
		s=dfs(d+1,a[d],c-1);
		q=dfs(d+1,a[d+1],c);
	}
	else{
		s=dfs(d+1,z&a[d],c-1);
		q=dfs(d+1,z,c);
	}
	return max(s,q);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	printf("%lld",dfs(1,a[1],m));
	return 0;
}
