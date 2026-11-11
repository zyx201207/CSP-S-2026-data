#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(long long i=2;i<=n;i++){
		a[i]=abs(a[i]-a[i-1]); 
		b[i]=b[i-1]+a[i];
	}
	long long ans=0;
	sort(b+1,b+1+n);
	for(long long i=1;i<=n;i++){
		if(b[i]<=k)ans++;
	}
	cout<<ans;
	return 0;
} 
