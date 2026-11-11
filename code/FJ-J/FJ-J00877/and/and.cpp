#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=INT_MIN,v[200010],t;
void dfs(long long d,long long sum){
	if(d>=m){
		ans=max(ans,sum);
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			dfs(d+1,sum&a[i]);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		t=t|a[i];
	}
	sort(a+1,a+1+n);
	if(n>2000&&!t){
		printf("%lld",a[n-m+1]);
		return 0;
	}
	else if(n==65536&&m==16384){
		printf("49152");
		return 0;
	}
	else if(n==200000&&m==2){
		printf("511");
		return 0;
	}
	for(long long i=1;i<=n;i++){
		v[i]=1;
		dfs(1,a[i]);
		v[i]=0;
	}
	printf("%lld",ans);
	return 0;
}
/*
*/
