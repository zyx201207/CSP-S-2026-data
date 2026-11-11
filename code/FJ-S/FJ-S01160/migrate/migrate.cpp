#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[2000100],ans;
long long f(long long x){
	long long l=1,r=n,mid,ans;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<max(0ll,n-(m*2-1))<<'\n';
	}
	return 0;
}
//time is not enough
//i'll die
//l love C:c_f
//give me more points
