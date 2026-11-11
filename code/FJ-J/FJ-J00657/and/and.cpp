#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout); 
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	} 
	sort (a,a+n); 
	int cnt = a[n-1];
	for (int i = n-2; i >= n-m; i--)
	{
		cnt = cnt&a[i];
	}
	cout << cnt;
	return 0;
 } 
