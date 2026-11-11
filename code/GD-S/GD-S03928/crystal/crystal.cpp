#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],s[N],ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		int l=1,r=i-1;
		while(l<=r) {
			int mid=l+r>>1;
			if((i-mid)*a[i]-s[i-1]+s[mid-1]<=m) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,1ll*i-l+1);
	}cout<<ans;
	return 0;
}
