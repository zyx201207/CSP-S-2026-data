#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],l,r,mid,ans,s[N],cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+(a[n]-a[i]);
	}
	l=1,r=n;
	while(l<=r){
		mid=l+r>>1;
		ll fl=0;
		for(ll i=n;i>=mid;i--){
			cnt=s[i]-s[i-mid]-(a[n]-a[i])*mid;
			if(cnt<=m){
				fl=1;
				break;
			}
		}
		if(fl){
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
