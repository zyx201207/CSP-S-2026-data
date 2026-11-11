#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5;
ll a[N];
bool cmp(const ll x,const ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ll x=a[1];
	for(ll i=2;i<=m;i++)x&=a[i];
	cout<<x;
	return 0;
}
