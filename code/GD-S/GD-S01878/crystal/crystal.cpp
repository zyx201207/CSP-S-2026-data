#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans=1;
ll sum=1;
ll n=0,m=0;
vector<ll> a;

bool answer(int e, int k) {
	sum=1;
	ll cnt=0;
	for(int i=0;i<e;i++) {
		if(cnt>=m) {
			if(a[i]==k && cnt==m) {
				sum++;
				ans=max(ans,sum);
				return true;
			}
			else return false;
		}
		cnt+=(k-a[i]);
		sum++;
	}
	if(cnt<=m) {
		ans=max(ans,sum);
		return true;
	}
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll l=0,r=n;
	while(l<r) {
		ll mid=(l+r)/2; 
		if(answer(mid,a[mid])) {
			l=mid+1;
		} else {
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}
