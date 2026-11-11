#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,x=0;
	for(int i=2;i<=n;i++){
		x+=(i-l)*(a[i]-a[i-1]);
		while(x>m)x-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
