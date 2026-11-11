#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m; 
const int N=5e5+100;
int a[N],sum[N];
inline int read() {int x;cin>>x;return x;}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	n=read();m=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	int l=1;
	int ans=0;
	for(int i=1;i<=n;i++) {
		while(1ll*a[i]*(i-l+1)-(sum[i]-sum[l-1])>m) {
			l++;
		}
		ans=max(ans,i-l+1);
//		cerr<<l<<" "<<i<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*

*/
