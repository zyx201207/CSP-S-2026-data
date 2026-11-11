#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long
ll n,m,ans=1;
ll a[N],sum[N];
vector<ll> e[N];
bool is_dc=true;
ll gd(int x,int y) {
	return a[x]-a[y];
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	ll gongcha=a[2]-a[1];
	for(int i=3; i<=n; i++) {
		if(a[i]-a[i-1]!=gongcha) {
			is_dc=false;
			break;
		}
	}

	if(is_dc) {
		ll cnt=0,tot=m;
		for(int i=1; i<=n; i++) {
			tot-=(i-1)*gongcha;
			cnt+=tot>=0;
		}
		ans=cnt;
	} else {
		sort(a+1,a+1+n);
		for(int i=2; i<=n; i++) {
			ll tot=m,cnt=0;
			for(int j=1; j<=i; j++) {
				
				tot-=gd(i,j);
				if(tot<0) {
					break;
				}cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	cout << ans<<endl;


	return 0;
}
