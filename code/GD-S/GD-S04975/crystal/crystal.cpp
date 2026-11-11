#include<bits/stdc++.h>
#define ll long long
using namespace std;
//long long!!!!
int n;
ll a[500010],m;
ll ans=1,d[500010],s[500010],dta;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) {
		dta=a[i]-a[1];
		d[i]=d[i-1]-(a[i]-a[i-1]);
		s[i]=s[i-1]+d[i];	
		int l=1,r=i,p=i;
		while(l<=r) {
			int mid=(l+r)/2;
			if(s[i]+dta*i-(s[mid-1]+dta*(mid-1))<=m) {
				r=mid-1;
				p=mid;
			} else l=mid+1;
		}
		ans=max(ans,i-p+1ll);
	}
	cout<<ans;
	return 0;
}
/*
4 5
0 2 4 5
*/
