#include<bits/stdc++.h>
using namespace std;
#define int long long
//luogu id afewdgre
int n,m,a[500005];
bool check(int mid){
	int sum=0;
	for(int i=1;i<=mid;i++) sum+=a[i];
	if(a[mid]*mid-sum<=m) return 1;
	for(int i=mid+1;i<=n;i++){
		sum+=a[i]-a[i-mid];
		if(a[i]*mid-sum<=m) return 1;
	} 
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
}
