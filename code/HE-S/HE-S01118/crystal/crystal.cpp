#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0,cnt1=1,cnt2=1;
	ll cur=0;
	for(ll i=2;i<=n;i++){
		if(a[i-1]!=a[i])
		cur+=((i-cnt2)*(a[i]-a[i-1]));
		cnt1++;
		if(cur>m)
		while(cur>m){
			cur=cur-(a[i]-a[cnt2]);
			cnt2++;
			cnt1--;
			if(cnt2>=n)
			break;
		}
		ans=max(cnt1,ans);
	}
	cout<<ans;
	return 0;
}
