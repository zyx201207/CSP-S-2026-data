#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll n,m,a[MAXN];
bool check(ll nl){
	ll cnt=0;
	for(ll i=1;i<nl;i++){
		cnt+=a[nl]-a[i];
		if(cnt>m) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,r=n,ans=0;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
