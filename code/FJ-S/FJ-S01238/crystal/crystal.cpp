#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long n,m;
long long arr[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	sort(arr+1,arr+n+1);
	long long x=0,ans=0;
	for(long long l=1,r=1;l<=n&&r<=n&&l<=r;r++){
		x+=(arr[r]-arr[r-1])*((r-1)-l+1);
		while(x>m&&l<=r){
			x-=(arr[r]-arr[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
