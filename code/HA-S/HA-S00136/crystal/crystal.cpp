#include<bits/stdc++.h>
using namespace std;
const int N=500009;
#define int long long
int n,m,a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	int ans=0;
	for(int r=1;r<=n;r++){
		sum[r]=sum[r-1]+a[r];
		while(a[r]*(r-l+1)-(sum[r]-sum[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
