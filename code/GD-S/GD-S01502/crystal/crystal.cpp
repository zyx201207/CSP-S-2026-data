#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
long long n,m,a[500005],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	ans=1;
	while(r<n){
		sum+=(a[r+1]-a[r])*(r-l+1);
		r++;
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1ll);
	}
	cout<<ans;
	return 0;
}
