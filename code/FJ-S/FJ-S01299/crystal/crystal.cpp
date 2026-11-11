#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1); 
	ll j=1,s=0,ans=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) s+=(a[i]-a[i-1])*(i-j);
		while(s>m) j++,s-=(a[i]-a[j]);
		ans=max(ans,i-j+1);
	}
	cout << ans;
	return 0;
}

