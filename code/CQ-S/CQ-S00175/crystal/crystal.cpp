#include <bits/stdc++.h>
#define debug(x) cout<<#x<<" = "<<x<<' '
#define int long long
#define N 500010
using namespace std;

int n,m;
int a[N],sum[N];

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
}

bool Check(int len){
	for(int l=1;l+len-1<=n;l++){
		int r=l+len-1;
		int cost=a[r]*len-(sum[r]-sum[l-1]);
		if(cost <= m) return 1;
	}
	return 0;
}

int Lower_Bound(){ // solve
	int l=1,r=n,ans=1;
	while(l <= r){
		int mid=(l+r) >> 1,flag=Check(mid);
		if(flag) l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	init();
	cout<<Lower_Bound();
	return 0;
}
