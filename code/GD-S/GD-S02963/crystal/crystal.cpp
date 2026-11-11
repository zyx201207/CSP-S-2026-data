#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005],cf[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==1){
		printf("1");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cf[i]=a[i]-a[i-1];
	int L=1,R=2;
	long long res=cf[2],sum=cf[2];
	while(L<=R&&R<=n){
		if(res<=m){
			ans=max(ans,R-L+1);
			R++;
			res=res+cf[R]*(R-L);
			sum=sum+cf[R];
		}
		else{
			res=res-sum;
			sum=sum-cf[L+1];
			L++;
		}
	}
	printf("%d",ans);
	return 0;
}
