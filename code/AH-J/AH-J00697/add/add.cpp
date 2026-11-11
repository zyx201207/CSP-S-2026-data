#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010];
void try6(){
	ll maxn=0;
	for(ll i=1;i<=n;i++) maxn=max(maxn,a[i]);
	cout<<maxn;
}
void try7(){
	ll cnt=a[1];
	for(ll i=2;i<=n;i++) cnt&=a[i];
	cout<<cnt;
}
void try8to10(){
	ll maxn=0;
	for(ll i=1;i<=n;i++)
		for(ll j=i+1;j<=n;j++)
			maxn=max(maxn,a[i]&a[j]);
	cout<<maxn;
}
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","W",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(m==1) try6();
	else if(m==n) try7();
	else if(m==2) try8to10();
	else{
		sort(a+1,a+1+n,cmp);
		ll ans=a[1];
		for(ll i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
