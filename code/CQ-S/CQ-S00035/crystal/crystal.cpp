#include<bits/stdc++.h>
using namespace std;
long long a[500005],s1[500005];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	long long l=1,r=1;
	long long cnt=0,sum=0;
	while(r<n){
		r++;
		cnt=r-l+1;
		sum=sum+(cnt-1)*(a[r]-a[r-1]);
		while(sum>m&&l<=r){
			sum-=a[r]-a[l];
			l++;
		}
		cnt=r-l+1;
		ans=max(ans,cnt);
		//cout<<l<<" "<<r<<" "<<sum<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
} 
