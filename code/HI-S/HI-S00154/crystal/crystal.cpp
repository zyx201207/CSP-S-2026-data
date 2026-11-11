#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, m, t, minn=27787789113;
ll a[600005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	//printf("%lld %lld\n", n, m);
	for(ll i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		//minn=min(a[i], minn);
		a[i]+=1000000000005;
	}
	sort(a+1, a+n+1);
	ll l=1, r=n, mid;
	for(ll i=1;i<=n;i++){
		a[i]-=1000000000005;
	}
	//printf("%d %d", a[1], minn);
	while(l<=r){
		//printf("t=%lld L=%lld r=%lld mid=%lld a[mid]=%lld\n", t, l, r, mid, a[mid]);
		t=0;
		mid=(l+r)/2;
		for(ll i=1;i<=mid;i++){
			t+=a[mid]-a[i];
			//cout << a[i] << endl;
			//printf("i=%lld a[i]=%lld a[mid]-a[i]=%lld\n", i, a[i], a[mid]-a[i]);
		}
		//printf("t=%lld\n", t);
		if(t>m){
			r=mid-1;
			//printf("t=%lld r=%lld r=mid-1\n", t, r);
		}else if(t<=m){
			l=mid+1;
			//printf("l=mid+1\n");
		}
		//printf("t=%lld L=%lld r=%lld mid=%lld a[mid]=%lld\n", t, l, r, mid, a[mid]);
	}
	t=0;
	for(int i=1;i<=r;i++){
		t+=a[r]-a[i];
	}
	printf("%lld\n", r);
	return 0;
}
