#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=a[n];
	m--;
	for(int i=n-1;i>=1&&m>0;i--){
		ans=(ans&a[i]);
		m--;
	}
	cout<<ans;
	return 0;
}
