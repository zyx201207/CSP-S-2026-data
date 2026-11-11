#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m;
int a[N], pre[N];


inline bool check(int kal){
	for(int i=kal; i<=n; i++){
		if(a[i]*kal-(pre[i]-pre[i-kal])<=m){
			return true;
		}
	}
	return false;
}

inline int solve(){
	int ans=0;
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	return ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+a[i];
	}
	cout<<solve();
	return 0;
}
