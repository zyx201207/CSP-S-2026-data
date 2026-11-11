#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005],f[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int c=a[n];
	for (int i=n;i>=n-m+1;i--) c=c&a[i]; 
	cout<<c;
	return 0;
}
