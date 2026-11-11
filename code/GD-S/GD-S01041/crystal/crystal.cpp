#include<bits/stdc++.h>
using namespace std;
long long a[5000005]; 
long long b[5000005];
long long c[5000005];
long long ans = 0;
bool ss = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i =1;i<=n;i++){
		b[i] = a[i]-a[i-1];
	}
	for(long long i =1;i<=n;i++){
		c[i] = c[i-1]+b[i]*(i-1);
	}
	for(long long l =1;l<=n;l++){
		long long r = l;
		long long k = (c[r]-c[l])*l+c[l];
		while(k<=m&&r<=n){
			ans = max(ans,r-l+1);
			r++;
			k = (c[r]-c[l])*l+c[l];
		}
		l = r;
	}
	cout<<ans;
	return 0;
} 
