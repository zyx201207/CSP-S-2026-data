#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[500005],money,ans=1,cha[500005];
signed main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)cha[i]=a[i]-a[i-1];
	for (int i=2;i<=n;i++){
		money+=cha[i]*(i-1);
		if (m>=money)ans=i;
		else break;
	}
	cout<<ans;
	return 0;
}
