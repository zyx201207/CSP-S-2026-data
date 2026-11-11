#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m;
ll a[500005];
map <ll,ll> mp;
ll ans=0;

void dfs(ll deep) {
	mp.clear();
	for(ll i=1; i<=n; i++) {
		mp[a[i]]++;
		ans=max(ans,mp[a[i]]);
	}

	if(deep>=m) {
		return ;
	}
	for(ll i=1; i<=n; i++) {
		a[i]++;
		dfs(deep+1);
		a[i]--;
	}
	return ;
}

ll diff[500005];

bool check(int x) {
	memset(diff,0x3f,sizeof(diff));

	for(int i=1; i<=n; i++) {
		if(a[i]<=x) {
			diff[i]=x-a[i];
		}
	}

	sort(diff+1,diff+1+n);

	ll w=m,cnt=0;
	for(int i=1; i<=n; i++) {
		if(w>=diff[i]) {
			w-=diff[i];
			cnt++;
		} else {
			break;
		}
	}

	if(ans<=cnt) {
		ans=cnt;
		return 1;
	} else {
		return 0;
	}
}


int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;

	bool f=1;

	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i) {
			f=0;
		}
	}

	if(f==1) {
		for(int i=1;; i++) {
			if(m>=i) {
				m-=i;
				ans++;
			}else{
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}

	if(n<=5) {
		dfs(0);
		cout<<ans;
	} else {
		sort(a+1,a+1+n);

		ll l=1,r=n;
		while(l<=r) {
			ll mid=(r-l)/2+l;
			if(check(a[mid])==1) {
				l=mid+1;
			} else {
				r=mid-1;
			}
		}

		cout<<ans;
	}
	return 0;
}
