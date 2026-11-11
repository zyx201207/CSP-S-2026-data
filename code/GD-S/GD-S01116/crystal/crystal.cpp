#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll a[N],m;
ll ans;
bool cmp(int x,int y){return x<y;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	int l=n-1;
	ll s=m,now=1;
	while(l>=1&&a[n]-a[l]<=s)s-=(a[n]-a[l]),now++,l--;
	ans=now;
	for(int i=n-1;i>=1;i--){
		s+=(now-1)*(a[i+1]-a[i]);
		now--;
		while(l>=1&&a[i]-a[l]<=s)s-=(a[i]-a[l]),now++,l--;
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
} 
