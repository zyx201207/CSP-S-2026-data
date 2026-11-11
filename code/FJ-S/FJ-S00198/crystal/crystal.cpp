#include <bits/stdc++.h>
#define int long long
#define rint register int
#define il inline
#define ms memset
using namespace std;
int n,m;
int a[500005];
int s[500005];
int l=0;
int ans;
signed main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(rint i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(rint i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(rint i=1;i<=n;i++){
		while(s[i]-s[l]+m<a[i]*(i-l)){
			l++;
		}
		ans=max(ans,i-l);
	}
	cout<<ans<<'\n';
	return 0;
}

