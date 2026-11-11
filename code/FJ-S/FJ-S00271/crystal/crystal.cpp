#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,p,ans,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	p=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while(a[i]*(i-p)-(sum[i-1]-sum[p-1])>m)p++;
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
