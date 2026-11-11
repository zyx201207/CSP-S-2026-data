#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N],c[N];
bool check(int x){
	int ans=1e18;
	for(int i=x;i<=n;i++){
		int cnt=a[i]*x-(c[i]-c[i-x]);
		ans=min(ans,cnt);
	}
	return ans<=m;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	while(T--)solve();
	return 0;
}