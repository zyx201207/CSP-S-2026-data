#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],n,m,c[N],s1[N],s2[N];
ll sum(int l,int r){
	return s2[l]-s2[r+1]-(r-l+1)*s1[r+1];
}
bool check(int l,int r){
	return sum(l,r)<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	n--;
	for(ll i=n;i>=1;i--)s1[i]=s1[i+1]+c[i];
	for(ll i=n;i>=1;i--)s2[i]=s2[i+1]+s1[i];
	ll ans=0;
	for(ll i=1;i<=n+1;i++){
		ll l=1,r=i-1,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i-1)){
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
