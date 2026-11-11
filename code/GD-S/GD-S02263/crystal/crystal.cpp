#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
long long n,m,a[maxn],sum[maxn],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		long long l=0,r=i;
		while(r-l>1){
			long long mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid;
			else l=mid;
		}
//		cout<<i<<" "<<r<<endl;
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
} 
