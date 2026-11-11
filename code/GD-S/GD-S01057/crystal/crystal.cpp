#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll a[maxn];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	ll n,m; cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=1;
	ll cur=0;
	for(int i=2,j=1;i<=n;++i) {
		cur+=1ll*(i-j)*(a[i]-a[i-1]);
		while(j<i&&cur>m) cur-=(a[i]-a[j++]);
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
} 
