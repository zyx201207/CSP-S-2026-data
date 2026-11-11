#include<bits/stdc++.h>
using namespace std;
int m,n,di=0;
long long ans=0,a[200005],dp[200005][2];
bool bo[200005];
int op(long long p){
	int hh=0;
	while(p!=1){
		if(p%2==1) hh++;
		p/=2;
	}
	return hh;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=max(1,n-25);i--){
		if(dp[1][1]<op(a[i])){
			dp[1][0]=a[i];
			dp[1][1]=op(a[i]);
			di=i;
		}
	}
	bo[di]=1;
	for(int i=2;i<=m;i++){
		di=0;
		for(int j=n;j>=max(n-30000,1);j--){
			int p=dp[i-1][0]&a[j];
			if(p>dp[i][0] && bo[j]==0){
				dp[i][0]=p;
				di=j;
			}
		}
		bo[di]=1;
	}
	printf("%lld",dp[m][0]);
	return 0;
}
