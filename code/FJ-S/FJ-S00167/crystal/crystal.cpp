#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll ans=0;
	for(ll i=1,j=1;i<=n;i++){
		while(a[i]*(i-j+1ll)-(sum[i]-sum[j-1])>m&&j<=i)j++;
		ans=max(ans,i-j+1ll);
	}
	cout<<ans;
}
