#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n;
long long a[N],m,ans;
bool check(long long mid){
	long long sum=0;
	for(int i=1;i<mid;i++){
		sum+=(a[mid]-a[i]);
	}
	if(sum<=m){
		return 1;
	}
	for(int i=mid+1;i<=n;i++){
		long long c=a[i]-a[i-1];
		sum=sum-a[i-mid]+c*mid;
		if(sum<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
