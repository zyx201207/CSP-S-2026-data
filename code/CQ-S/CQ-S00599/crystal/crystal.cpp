#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int ans,sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int r=1,l=1;r<=n;r++){
		sum+=a[r];
		for(;l<=r;l++){
			if((r-l+1)*a[r]-sum<=m)break;
			sum-=a[l];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
