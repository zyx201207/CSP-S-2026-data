#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,ans;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll len=1;len<=n;len++){
		for(ll l=1;l+len-1<=n;l++){
			ll Max=0,r=l+len-1,sum=0;
			for(ll i=l;i<=r;i++) Max=max(Max,a[i]);
			for(ll i=l;i<=r;i++) sum+=Max-a[i];
			if(sum<=m){
				ans=max(ans,len);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
