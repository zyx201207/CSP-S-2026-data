#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=n+1,r=n,sum=0,ans=0;
	while(r>=1){
		while(l>=1&&sum+a[r]-a[l-1]<=m){
			l--;
			sum+=a[r]-a[l];
		}
		ans=max(ans,r-l+1);
		sum-=(a[r]-a[r-1])*(r-l);
		r--;
	}
	cout<<ans;
	return 0;
}
