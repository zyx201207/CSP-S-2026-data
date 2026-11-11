#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int N=5e5+5;
int n,m,ans;
int a[N],sum[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		for(;sum[i-1]-sum[j-1]+m<a[i]*(i-j);) j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
