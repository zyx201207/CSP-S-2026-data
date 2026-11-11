#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005];
bool check(int k){
	bool flag=0;
	for(int i=1;i<=n-k+1;i++) if(a[i+k-1]*k-b[i+k-1]+b[i-1]<=m) flag=1;
	return flag;
}signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}cout<<l;
	return 0;
}
