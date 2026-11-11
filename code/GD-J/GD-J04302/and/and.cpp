#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	int a[n] = {0};
	for(int i = 0;i<n;i++) cin>>a[i];
	sort(a,a + n);
	x = a[n - 1];
	if(m == 1) cout<<a[n - 1];
	for(int i = n - 1;i>=n - m;i--) x = (x & a[i]);
	cout<<x;
	return 0;
}
