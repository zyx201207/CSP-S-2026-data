#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+5;
int n,m,ans;
ll a[N],q[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	q[n]=0;
	for(int i=n-1;i>=1;i--) {
		q[i]=q[i+1]+a[n]-a[i];
	}
	int r=1;
	for(int i=1;i<=n;i++) {
		while(q[i]-q[r+2]-(a[n]-a[r+1])*(r-i+2)<=m&&r+1<=n) r++;
		ans=max(ans,r-i+1);
	}
	cout<<ans;
	return 0;
}
