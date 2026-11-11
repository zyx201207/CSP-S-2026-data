#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+11;
ll n,m,a[N],ans;
bool check(ll s){
	ll h=0;
	for(int i=1;i<=n;i++){
		h+=a[i];
		if(i>=s){
			h-=a[i-s];
			if(s*a[i]-h<=m)return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,r=n+1;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
