#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],awy[200005],maxn=-0x3f3f3f3f;
bool cmp(ll x,ll y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	awy[1]=a[1];
	for(ll i=2;i<=n;i++)
		awy[i]=awy[i-1]&a[i];
	for(ll i=1;i<=n-m+1;i++)
		maxn=max(maxn,awy[i]&awy[i+m-1]);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
