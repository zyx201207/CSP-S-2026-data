#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],qz[500010];
bool check(int sz){
	int l=1,r=sz;
	while (r<=n){
		int sum=0;
		double jl=(1.0*(1.0*qz[r]-qz[l-1])/(r-l+1));
		int mid=(qz[r]-qz[l-1])/(r-l+1);
		// for (int i=l;i<=r;i++){
		// 	sum+=abs(a[i]-a[l+(r-l)/2]);
		// }
		// if (sum<=m){
		// 	return true;
		// }
		// l++;
		// r++;
		if (jl-mid!=0){
			l++;
			r++;
			continue;
		}
		sum=(qz[r]-qz[l-1])-mid*(r-l+1);
		if (sum<=m){
			return true;
		}
		l++;
		r++;
	}
	return false;
}
int ef(int l,int r){
	int ans=0,mid=0;
	while (l<=r){
		mid=l+(r-l)/2;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
	}
	cout<<ef(1,n);
	return 0;
}