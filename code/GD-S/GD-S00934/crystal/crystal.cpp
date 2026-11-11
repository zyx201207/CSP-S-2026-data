#include<bits/stdc++.h>
using namespace std;
long long a[500001],n,m;
long long pre[500001];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		long long sum=a[i+x-1]*(x-1)-pre[i+x-2]+pre[i-1];
		if(sum<=m) return true;
	}
	return false;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	} 
	cout << r;
	return 0;
} 
