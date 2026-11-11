#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
bool check(ll k){
	ll num = 0;
	for(int i = 1;i<=n;i++){
		if(a[i]<=k)num +=k-a[i];
		else break;
	}
	return num <= m ? 1 : 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l = 0,r = 1e12;
	ll mid = (l+r)/2;
	while(l<r){
		mid = (l+r)/2;
		if(check(mid)){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(a[i] <= mid)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
