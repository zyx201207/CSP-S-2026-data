#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool check(long long x){
	long long sum=0;
	for(long long i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,ans=-1;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
