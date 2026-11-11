#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000010;
int n,m,a[N];
bool check(int x){
	bool ok=0;
	int sum=0;
	for(int i=1;i<=x;i++) sum+=a[x]-a[i];
	if(sum<=m) ok=1;
	for(int i=x+1;i<=n;i++){
		sum-=(a[i-1]-a[i-x]);
		sum+=(x-1)*(a[i]-a[i-1]);
		if(sum<=m) ok=1;
	}
	return ok;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int maxx=LLONG_MIN,minx=LLONG_MAX;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]),minx=min(minx,a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<l-1;
}

