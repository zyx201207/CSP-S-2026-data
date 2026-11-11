#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N],n,m;
bool check(int k){
	int cnt=0;
	for(int i=1;i<=k;i++) cnt+=(a[k]-a[i]);
	if(cnt<=m) return 1;
	for(int i=k+1;i<=n;i++){
		cnt-=(a[i-1]-a[i-k]);
		cnt+=(k-1)*(a[i]-a[i-1]);
		if(cnt<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(r-l>>1)+l;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
