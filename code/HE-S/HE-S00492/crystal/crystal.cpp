#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],sum[N];
inline bool check(int x){
	for (int i=x;i<=n;i++){
		long long k=sum[i]-sum[i-x];
		if (k+m>=1ll*a[i]*x) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid;
	while (l<r){
		mid=(l+r+1)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<'\n'; 
	return 0;
} 
