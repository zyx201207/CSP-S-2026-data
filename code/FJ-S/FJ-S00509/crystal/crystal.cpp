#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,ans,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++){
		while((a[i]-a[i-1])*(i-l)-a[i]+a[l]>m)l++;
		ans=max(ans,i-l);
	}cout<<ans;
}
