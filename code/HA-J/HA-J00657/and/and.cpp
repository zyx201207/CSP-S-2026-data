#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001];
long long solve(int i,bool ok,int la,int c){
	if(c>m){
		return 0;
	}
	if(i == n+1){
		if(c==m)
		return la;
		return 0;
	}
	if(ok){
		long long l = solve(i+1,0,a[i],c+1)&a[i],r = solve(i+1,1,a[i],c+1)&a[i];
		long long ret = max(l,r);
		return ret;
	}else{
		long long l=solve(i+1,0,la,c),r = solve(i+1,1,la,c);
		long long ret = max(l,r);
		return ret;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	printf("%lld",max(solve(1,0,0,0),solve(1,1,0,0)));
	return 0;
}
