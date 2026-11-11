#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NUM=2e5+5;
map<pair<ll,ll>,char> ma;
pair<ll,ll> num[NUM];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,ld=0;
	cin>>n;
	for(ll i=0; i<n; i++) {
		ll d;
		char nam;
		cin>>d>>nam;
		ma[ {ld,ld+d-1}]=nam;
		num[i]= {ld,ld+d-1};
		ld+=d;
	}
	for(ll i=0; i<n; i++) {
		ll a=num[i].first,b=num[i].second;
		if(a<=ld/2&&b>=ld/2&&ld%2==0) {
			for(int p=n; p>i+1; p--) {
				num[p]=num[p-1];
			}
			char dat=ma[ {a,b}];
			num[i]= {a,ld/2-1};
			ma[ {a,ld/2-1}]=dat;
			num[i+1]= {ld/2,b};
			ma[ {ld/2,b}]=dat;
			n++;
			break;
		}
		if(ld%2==1&&a<=ld/2&&b>=ld/2) {
			char dat=ma[ {a,b}];
			if(a==ld/2&&b==ld/2) {
				for(int p=i; p<n; p++) {
					num[p]=num[p+1];
				}
				n--;
			} else if(a<ld/2&&b==ld/2) {
				num[i]= {a,ld/2-1};
				ma[ {a,ld/2-1}]=dat;
			} else if(a==ld/2&&b>ld/2) {
				num[i]= {ld/2+1,b};
				ma[ {ld/2+1,b}]=dat;
			} else if(a<ld/2&&b>ld/2) {
				for(int p=n; p>i+1; p--) {
					num[p]=num[p-1];
				}
				num[i]= {a,ld/2-1};
				ma[ {a,ld/2-1}]=dat;
				num[i+1]= {ld/2+1,b};
				ma[ {ld/2+1,b}]=dat;
				n++;
			}
			break;
		}
	}
	ll l=0,r=n-1;
	ll ans=0;
	while(r>l) {
		ll a=num[l].first;
		ll b=num[l].second;
		ll c=num[r].first;
		ll d=num[r].second;
		if(b-a+1>d-c+1) {
			ll sum=d-c+1;
			if(ma[ {a,b}]!=ma[ {c,d}]) {
				ans+=sum;
			}
			num[l]= {a+sum,b};
			ma[ {a+sum,b}]=ma[ {a,b}];
			r--;
		} else if(b-a+1<d-c+1) {
			ll sum=b-a+1;
			if(ma[ {a,b}]!=ma[ {c,d}]) {
				ans+=sum;
			}
			num[l]= {c,d-sum};
			ma[ {c,d-sum}]=ma[ {c,d}];
			l++;
		} else if(b-a+1==d-c+1) {
			if(ma[ {a,b}]!=ma[ {c,d}]) {
				ans+=b-a+1;
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}



