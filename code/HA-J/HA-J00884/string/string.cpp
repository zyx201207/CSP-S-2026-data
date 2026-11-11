#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	ll num;
	char c;
};

ll n;
node a[200005];
ll ans=0;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i].num>>a[i].c;
	}

	ll l=1,r=n;

	while(l<=r) {
		ll diff=min(a[l].num,a[r].num);

		if(a[l].c!=a[r].c) {
			ans+=diff;
		}

		if(diff==a[l].num) {
			l++;
		} else {
			a[l].num-=diff;
		}

		if(diff==a[r].num) {
			r--;
		} else {
			a[r].num-=diff;
		}
	}

	cout<<ans;
	return 0;
}
