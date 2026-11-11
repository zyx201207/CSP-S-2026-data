//GZ-S00232   兰弟军   遵义周林学校
#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long long i=1; i<=n; i++) {
		for(long long j=1; j<=n; j++) {
			if(a[j]>a[j-1]) {
				long long k=a[j];
				a[j]=a[j-1];
				a[j-1]=k;
			}
		}
	}
	long long cha=m,r,ma=0,k=0;
	for(long long i=n-1; i>0; i--) {
		for(long long j=n; j>=i; j--) {
			r=a[i]-a[j];
			cha=cha-r;
			if(cha>=0) k++;
			else cha=m;
			if(k>ma) ma=k;
		}
		cha=m;
		k=0;
	}
	cout<<ma;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

