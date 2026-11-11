#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500001],m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int now=1,ans=0;
	for(int i=1;i<=n;i++){
		m-=(a[i]-a[i-1])*(i-now);
		while(m<0) m+=a[i]-a[now++];
		ans=max(i-now+1,ans);
	}
	cout<<ans;
	return 0;
}
//easy
