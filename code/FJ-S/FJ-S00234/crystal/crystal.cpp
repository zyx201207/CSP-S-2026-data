#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl;
ll a[500010];
ll sum[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&1ll*(j-i+1ll)*a[j]-(sum[j]-sum[i-1])<=m)j++;
		j--;
		ans=max(ans,j-i+1);
	}
	cout<<ans<<endl;
	return 0;
}

