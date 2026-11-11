#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(int a,int b)
{
	return (a & 1111111111) > (b & 1111111111);
}
int main()
{
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	int n,m;
	long long x;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a + 1,a + n + 1,cmp);
	x = a[1]; 
	for (int i = 1 ; i <= m ; i ++)
		x = (x & a[i]);
	cout << x;
	return 0;
}
