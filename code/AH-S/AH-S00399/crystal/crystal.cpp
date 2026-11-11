#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn,sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=2;
	maxn=1;
	while(l<=n){
		if(r<=n&&a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m){
			r++;
		}else{
			l++;
		}
		maxn=max(maxn,r-l);
	}
	cout<<maxn;
	return 0;
}
