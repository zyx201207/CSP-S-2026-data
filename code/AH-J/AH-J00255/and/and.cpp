#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	long long sum=a[n];
	for(int i = n-1; i >= n-m+1; i--)
	{
		sum&=a[i];
	}
	cout << sum;
	return 0;	
}
