#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxx=-1,sum=0;
	cin>>n>>m;
	long long a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			sum=a[i+j]&a[i+j+1];
		}
		if(sum>maxx) {
			maxx=sum;
		}
	}
	cout<<maxx;
	return 0;
}
