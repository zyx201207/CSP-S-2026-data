#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
bool check(int cv){
	int sum=0;
	for(int i=1;i<=cv;i++) sum+=a[cv]-a[i];
	if(sum<=m) return 1;
	for(int i=2;i+cv-1<=n;i++){
		int to=i+cv-1;
		sum-=a[to-1]-a[i-1],sum+=(cv-1)*(a[to]-a[to-1]);
		if(sum<=m) return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
