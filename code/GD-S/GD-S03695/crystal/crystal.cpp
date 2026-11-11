#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,lq=1,sum,ans;
ll a[N],qzh[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
	for(ll i=1;i<=n;i++) {
		while(lq<=i&&(i-lq+1)*a[i]-(qzh[i]-qzh[lq-1])>m) {
			lq++;
		}
		ans=max(ans,i-lq+1);
	}
	cout<<ans<<"\n";
}
