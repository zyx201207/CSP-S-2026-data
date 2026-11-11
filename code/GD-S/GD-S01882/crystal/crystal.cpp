#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
const long long INF=0x3f3f3f3f3f3f3f3f;
int n;
long long a[maxn],sum[maxn],m;
bool check(int x){
	long long ans=INF;
	for(int i=x;i<=n;i++){
		ans=min(1ll*(x-1)*a[i]-sum[i-1]+sum[i-x],ans);
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid; 
		else r=mid-1;
	}
	cout << l;
	return 0;
} 
