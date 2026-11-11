#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
int n,m,a[N],minn=1e13,maxn=-1e13,ans;

bool check(int x){
	int sum=0;
	for (int i=1;i<=n;i++){
		if (a[i]<x) {sum+=(x-a[i]);}
		if (a[i]>=x) break;
		if (sum>m) return false;
	}
	if (sum>m) return false;
	else return true;
}

signed main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	int l=minn-1,r=maxn+1,mid;
	while (l<r){
		mid=(l+r-1)/2+1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	for (int i=1;i<=n;i++){
		if (a[i]<=r) ans++;
		else break;
	}
	cout<<ans;
	return 0;	
}
