#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long maze;
bool dif;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		if (a[i]!=a[0]) dif=true;
	}
	if (!dif) {
		cout<<n;
		return 0;
	}
	sort(a,a+n);
	for (int i=n-1; i>=0; i--) {
		long long sum=0;
		for (int j=0; j<i; j++) {
			sum+=(a[i]-a[j]);
		}
		if (sum<=m) {
			cout<<i+1;
			return 0;
		}
	}
	cout<<1;
	return 0;
}
