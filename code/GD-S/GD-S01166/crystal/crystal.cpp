#include<bits/stdc++.h>
using namespace std;
#define int long long



int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=0,j=1,ans=0;
	for(int i=1;i<=n;i++){
		cnt=cnt+(i-j)*(a[i]-a[i-1]);
		while(cnt>m)cnt-=(a[i]-a[j]),j++;
		ans=max(i-j,ans);
	}
	cout<<ans+1;
	return 0;
}
