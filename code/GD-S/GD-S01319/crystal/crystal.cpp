#include <bits/stdc++.h>

using ll=long long;

const int MAXN=5e5+10;

ll ans;

ll a[MAXN];
//ll vis[MAXN];

struct Node {
	int fi,se;
};

std::map<int,Node>mp;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ll n,m;
	scanf("%lld%lld",&n,&m);

	for(int i=1; i<=n; ++i)
		scanf("%lld",&a[i]);

	std::sort(a+1,a+1+n);

	for(int i=1; i<=n; ++i) {
		mp[a[i]].fi++;
		mp[a[i]].se=std::max(mp[a[i]].se,i);
	}

	int xb=0,Max=0;
	for(auto tmp:mp) {
		if(tmp.first>=Max) {
			Max=tmp.second.fi;
			xb=tmp.second.se;
		}
	}

	auto check=[&](ll x)->bool {
		ll mm=m;
		ll sum=1;

		for(int i=x+1; i<=n; ++i) {
			if(a[i]==a[x])sum++;
			else break;
		}
		for(int i=x-1; i>0; --i) {
			if(mm>=a[x]-a[i]) {
				++sum;
				mm-=(a[x]-a[i]);
//				printf("%lld:%lld\n",ans,m);
			} else {
				break;
			}
		}

		bool rn=(sum>=ans);
		ans=std::max(ans,sum);

		return rn;
	};

	check(xb);

	ll l=1ll,r=n;
	while(l<=r) {
		ll mid=(l+r)>>1ll;
		if(check(mid)) {
			l=mid+1ll;
		} else {
			r=mid-1ll;
		}
	}

	printf("%lld\n",ans);

	return 0;
}

/*
Input:
5 5
1 2 4 8 9

Input:
5 8
-3 -1 2 2 7
*/
