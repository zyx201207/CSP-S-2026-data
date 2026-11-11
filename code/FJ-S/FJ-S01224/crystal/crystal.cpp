#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+15;
int n,ans;
ll m,a[N],sum;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int r=1,l=1;r<=n;r++) {
		sum+=(ll)(r-l)*(a[r]-a[r-1]);
		while(l<=r&&sum>m) {
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
