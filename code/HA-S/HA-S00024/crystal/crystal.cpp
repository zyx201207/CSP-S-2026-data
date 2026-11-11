#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(ll i=2;i<=n;i++){
		ll j=i-1;
		while(a[i]*(i-j+1)-s[i]<=m && j>0) j--;
		ans=max(ans,i-j);
	}
	cout<<ans<<"\n";
	return 0;
}
