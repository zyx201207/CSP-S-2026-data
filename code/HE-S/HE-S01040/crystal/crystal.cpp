#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],s[N];
ll bs(ll L,ll R,ll i){
	ll l=L,r=R,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(s[i]-s[mid-1]+m>=a[i]*(i-mid+1)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int mx=1;
	for(int i=1;i<=n;i++){
		int id=bs(1,i,i);
		mx=max(mx,i-id+1);
	}
	cout<<mx;
	return 0;
}
