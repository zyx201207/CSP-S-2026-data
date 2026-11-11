#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int s=0,l=1,ans=0;
	for(int i=1;i<=n;i++){
		s+=(a[i]-a[i-1])*(i-l);
		while(s>m) s-=(a[i]-a[l++]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

