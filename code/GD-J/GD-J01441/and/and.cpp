#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(register int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	cout << (a[1] & a[2]);
	return 0;
}
