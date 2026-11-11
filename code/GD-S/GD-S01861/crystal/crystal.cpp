#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,sum,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int l=1,r=0;l<=n&&r<=n;){
		while(r<n&&sum+cnt*(a[r+1]-a[r])<=m) sum+=cnt*(a[r+1]-a[r]),cnt++,r++;
		ans=max(ans,r-l+1);
		sum+=cnt*(a[r+1]-a[r]),cnt++,r++;
		while(sum>m) sum-=a[r]-a[l],cnt--,l++;
	}
	cout<<ans;
	return 0;
}
