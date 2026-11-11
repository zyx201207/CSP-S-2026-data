#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],l=1,zd,s;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s+=(i-l)*(a[i]-a[i-1]);
		while(s>k) s-=a[i]-a[l++];
		zd=max(zd,i-l+1);
	}
	cout<<zd;
	return 0;
}
