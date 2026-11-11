#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5+10;
long long n,k,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	long long ans = 0;
	for(long long i = 1;i<=n-k;i++){
		long long c = a[i];
		for(long long j = i;j<=k+i;j++){
			c = (c&a[j]);
		}
		ans = max(ans,c);
	}
	cout<<ans;
	return 0;
}
