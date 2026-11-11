#include<bits/stdc++.h>
using namespace std;
int n;
long long a[510000];
long long m;
long long pre[510000];
long long ans=1100000000000000000;
int check(int mk){
	ans=1100000000000000000;
	for(int i=1;i+mk-1<=n;i++){
		long long p=pre[i+mk-1]-pre[i-1];
		long long x=a[i+mk-1]*mk;
		ans=min(ans,abs(p-x));
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	
	
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int L=0,R=n+1;
	while(L+1<R){
		int M=(L+R)/2;
		
		if(check(M)<=m) L=M;
		else R=M;
		
	}
	printf("%d",L);
	return 0;
}
