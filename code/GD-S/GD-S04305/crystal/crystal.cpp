#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],s[500010];
bool check(long long x){
	long long k=1e18+1;
	for(long long i=x;i<=n;i++)
		k=min(k,a[i]*(x-1)-(s[i-1]-s[i-x]));
	return k<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	long long l=1,r=n,mid;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r<<'\n';
	return 0;
}
