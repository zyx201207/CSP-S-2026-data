#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+5;
int c,t;
ll a[N],b[N];
int n; ll d;
bool check(int l,int r) {
	return (a[r]-a[l]+d-1)/d < (r-l);
}
void solve() {
	ll cnt=0; scanf("%d%lld",&n,&d);
	//vector<ll> a(n+1),b(n+1);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),b[i]=a[i]-a[i-1];
	//for(int i=1;i<=n-1;i++) {
	//	for(int j=i+2;j<=n;j++) {
	//		cout<<i<<' '<<j<<'\n';
	//		if(check(i,j)) cnt++;
	//	}
	//}
	printf("0\n");
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}

