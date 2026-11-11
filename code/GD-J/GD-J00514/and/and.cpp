#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[200010];
bool cmp(ll a,ll b) {
	ll ansa=0,ansb=0;
	while(a) {
		if(a%2==1)ansa++;
		a/=2;
	}
	while(b){
		if(b%2==1)ansb++;
		b/=2;
	}
	if(ansa==ansb){
		return a>b;
	}
	return ansa>ansb;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}

	if(m==1) {
		sort(a+1,a+n+1);
		cout<<a[n];
	}  else if(m== 2) {
		ll sum;
		for(ll i=1; i<=n; i++) {
			for(ll j=i+1; j<=n; j++) {
				sum=max(sum,ll(a[i]&a[j]));
			}
		}
		cout<<sum;
	} else if(m==n) {
		ll sum=a[1];
		for(ll i=2; i<=n; i++) {
			sum&=a[i];
		}
		cout<<sum;
	} else if(m==n-1) {
		ll sum,cnt=0;
		for(ll i=1; i<=n; i++) {
			if(i==1)sum=a[2];
			else sum=a[1];
			for(ll j=1; j<=n; j++) {
				if(j==i)continue;
				sum&=a[j];
			}
			cnt=max(sum,cnt);
		}
		cout<<cnt;
	} else {
		sort(a+1,a+n+1,cmp);

		ll sum=a[1];
		for(ll i=1;i<=m)sum&=a[i];
		cout<<sum;

	}
	return 0;
}
