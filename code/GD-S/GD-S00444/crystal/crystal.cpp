#include<bits/stdc++.h>
using namespace std;
using ci=const int;using ui=unsigned int;using cui=const unsigned int;using ll=long long;
using cll=const long long;using ull=unsigned long long;using cull=const unsigned long long;
cui oo=1u<<30;cull inf=1ull<<62;
cui N=5e5+5;
ui n,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ui i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ui i=1,l=1;i<=n;i++){
		while(l<i&&m<0)m+=a[i]-a[l++];
		ans=max(ans,i-l+1),m-=ll(i-l+1)*(a[i+1]-a[i]);
	}
	cout<<ans;
	return 0;
}
