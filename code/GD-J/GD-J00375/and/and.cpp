#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(long long x,long long y) {
	return x>y;
}

long long n,m;
long long a[20005],ans=0;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	ans=a[0];
	for(long long i=0;i<m;i++) {
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
