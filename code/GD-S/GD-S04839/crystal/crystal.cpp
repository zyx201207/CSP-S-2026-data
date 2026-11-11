#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N],n,m,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	int l=0;
	for (int i=1;i<=n;i++){
		while (a[i]*(i-l)-(sum[i]-sum[l])>m)l++;
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}
