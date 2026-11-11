#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=5e5+5;
ll n,m,a[N],sum[N],p,ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];		
	}
	for(int i=1;i<=n;i++){
		while(p<=i&&1ll*(i-p)*a[i]-(sum[i]-sum[p])>m) p++;
		ans=max(ans,i-p);
	}
	cout<<ans<<'\n';
	return 0;
}