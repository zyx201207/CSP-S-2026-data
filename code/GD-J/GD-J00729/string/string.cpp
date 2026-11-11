#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
int n, a[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
	}
	int l=1, r=n;
	ll ans=0;
	while(l<=r) {
		if(l==r) break; 
		int cnt=min(a[l],a[r]);
		a[l]-=cnt;
		a[r]-=cnt;
		if(c[l]!=c[r]) {
			ans+=cnt;
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	printf("%lld", ans);
	return 0;
}
