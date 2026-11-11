#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[20100],b[20010];
signed main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
