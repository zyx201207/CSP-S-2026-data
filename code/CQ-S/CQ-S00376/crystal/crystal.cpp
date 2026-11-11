#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N],b[N];
bool check(int len){
	for(int i=len;i<=n;i++){
		if(a[i]*len-(b[i]-b[i-len])<=m) return 1;
	}
	return 0;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
