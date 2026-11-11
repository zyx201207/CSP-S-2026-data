#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[50000005];
int n,m;
int check(int x){
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=2;j<=x;j++) sum+=(a[j]-a[j-1]);
		if(sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)==1) l=mid;
		else r=mid-1;
	}
	if(check(r)==1) cout<<r;
	else cout<<l;
	return 0;
}
