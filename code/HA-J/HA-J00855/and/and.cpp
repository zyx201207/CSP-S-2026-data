#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,m,b;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b1;
	}
	b=a[n];
	for(int i=2;i<=m;i++){
		b=b and a[n-i];
	}
	cout<<b;
	return 0;
}
