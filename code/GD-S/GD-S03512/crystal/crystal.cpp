#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ma=LONG_LONG_MIN,mi=LONG_LONG_MAX,cnt;
bool check(long long x){
	long long sum=0;
	for (long long i=1;i<=n;i++){
		if (a[i]>=x) continue;
		else sum=sum+x-a[i];
	}
	if (sum>m) return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	long long l=mi,r=ma,mid=0;
	while (l<r){
		mid=l+r>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	sort (a+1,a+n+1);
	for (long long i=1;i<=n;i++){
		if (a[i]<=r) cnt++;
		else break;
	}
	cout<<cnt;
	return 0;
}
