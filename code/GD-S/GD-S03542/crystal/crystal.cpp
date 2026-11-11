#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005],sum[500005];
bool check(int x){
	x--;
	long long ans=0;
	long long minn=10e18;
	for(int i=1;i<=n-x;i++){
		ans=0;
		long long st=i,ed=i+x;
		while(st<ed){
			ans+=sum[ed]-sum[st];
			ed--;
			st++;
		}
		minn=min(minn,ans);
	}
//	cout<<x<<" "<<ans<<endl;
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		sum[i+1]=sum[i]+b[i];
		//cout<<sum[i+1]<<" ";
	}
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
} 
