#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+9;
int a[N],n,m,sum[N];
bool check(int t){
	for(int x=t;x<=n;x++){
		if(sum[x]-sum[x-t]-t*a[x]+m>=0) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
