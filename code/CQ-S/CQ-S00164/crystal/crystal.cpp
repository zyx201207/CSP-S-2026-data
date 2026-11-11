#include <bits/stdc++.h>
using namespace std;

int n,m;
long long he;
long long a[500005];
long long b[500005];
long long ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	
	long long j=1;
	for(long long i=1;i<=n;i++) {
		while((a[i]*i-(b[i]-b[j-1]))>m) j++;
		if((i-j+1)>ans) ans=i-j+1;
	}
	
	cout<<ans;
	return 0;
} 
