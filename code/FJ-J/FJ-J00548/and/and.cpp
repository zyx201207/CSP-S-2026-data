#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[200005],ans;
signed main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	if (m==1){
		sort (a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if (m==n){
		ans=a[1];
		for (int i=1;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if (m==n-1){
		sort (a+1,a+n+1);
		ans=a[1];
		for (int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if (m==2){
		sort (a+1,a+n+1);
		ans=a[n]&a[n-1];
		cout<<ans;
		return 0;
	}
	sort (a+1,a+n+1);
	cout<<a[1];
	return 0;
}
