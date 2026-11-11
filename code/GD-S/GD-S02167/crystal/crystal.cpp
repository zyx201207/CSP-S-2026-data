#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],l,r;
bool check(int k){
	for(int i=k;i<=n;i++){
		if((a[i]-a[i-1])*k-a[i]+a[i-k]<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)a[i]+=a[i-1];
	l=0,r=n+1;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
