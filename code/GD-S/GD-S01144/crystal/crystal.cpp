#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,m,ans=-1,cnt=0;
	cin>>n>>m;
	vector<ll> a(n,0),s(n,0);
	for(ll i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a.begin(),a.end(),less<ll>());
	s[0]=0;
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i-1];
	for(ll i=0;i<n;i++) {
		while(((i-cnt+1)*a[i]>s[i+1]-s[cnt]+m)&&(cnt<n)) cnt++;
		ans=max(ans,i-cnt+1);
	}
	cout<<ans;
	return 0;
} 
// 02:26:35 
