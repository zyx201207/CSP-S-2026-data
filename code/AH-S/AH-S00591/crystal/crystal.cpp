#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,p=0,ans=0,m,l=0,h,g=0;
	cin>>n>>m>>a[1]>>a[2];
	h=a[2]-a[1];	
	for (long long i=3;i<=n;i++){
		cin>>a[i];
		p=max(p,a[i]);
		if (a[i]==i) l++;
		if (i!=1 and a[i]==a[i-1]+h) g++;
	}
	
	if (l==n) {
		long long k=0;
		for (long long i=1;i<=n;i++) {
			if (m>=i) m-=i,k++;
			else {
				cout<<k;
				return 0;
			}
	}
	}
	
	if (g>=n-3 and n>5000) {
		long long k=0;
		for (long long i=1;i<=n;i++) {
			if (m>=i*h) m-=i*h,k++;
			else {
				cout<<k;
				return 0;
			}
	}
	}
	
	for (int i=1;i<=p;i++){
		long long q=0,m2=m;
		for (long long j=1;j<=n;j++) b[j]=0;
		for (long long j=1;j<=n;j++) {
			if (a[j]<i)b[j]=i-a[j];
			if (a[j]==i) q++;
		}
		sort (b+1,b+n+1);
		for (long long j=1;j<=n;j++) {
			if (b[j]) {
				if (m2>=b[j]) m2-=b[j],q++;
				else break;
				
			}
			
		}
		
		ans=max(ans,q);
	}
	cout<<ans;
	return 0;
}
