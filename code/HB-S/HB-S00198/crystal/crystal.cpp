#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],n,m,sum[500005],ans;
bool check(int x){
	int mi=4e18;
	for(int i=x;i<=n;i++){
		int s=sum[i]-sum[i-x];
		int cha=x*a[i]-s;
		mi=min(mi,cha);
	}
	return mi<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}
