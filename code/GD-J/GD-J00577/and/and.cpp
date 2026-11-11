#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	long long sum=a[0];
	if(n==m) {
		for(int i=0; i<n; i++) {
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	cout<<1;
}
