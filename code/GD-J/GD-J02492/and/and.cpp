#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;
ll n,m,ans = -1;
ll a[N];
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans = (a[1] & a[2]);
	for(int i = 1;i <= n;i++){
		ans = max({ans , (a[i-1]&a[i]) , (a[i+1]&a[i]) } );
	}
	cout<<ans;
	return 0;
}
