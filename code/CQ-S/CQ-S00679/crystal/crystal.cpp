#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,a[N],sum[N];
inline bool check(int l,int r){
	return (a[r]*(r-l+1)-(sum[r]-sum[l-1]))<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	int ans=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i)
		while(i-ans>0&&check(i-ans,i)) ++ans;
	cout<<ans;
	return 0;
}

