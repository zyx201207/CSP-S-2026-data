#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],s[N],maxn;
inline bool check(ll mid,ll wz){
	ll len=wz-mid+1;
	ll zhi=s[wz]-s[mid-1];
	if (a[wz]*len-zhi<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)>>1;
			if (check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		maxn=max(maxn,(i-r+1));
	}
	cout<<maxn;
	return 0;
}
