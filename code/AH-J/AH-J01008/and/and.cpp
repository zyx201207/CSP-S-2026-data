#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10000005];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	ll sum=a[1];
	for(ll i=2;i<=m;i++) sum&=a[i];
	printf("%lld",sum);
	
	return 0;
}
