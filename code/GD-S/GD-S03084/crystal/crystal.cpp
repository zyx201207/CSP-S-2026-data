#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN=5e5;
int n,m;
int a[MAXN+5],s[MAXN+5];

bool check(int x){
	for(int i=x;i<=n;++i) if(a[i]*(x-1)-(s[i-1]-s[i-x])<=m) return true;
	return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	int ans=1,l=2,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
