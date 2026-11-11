#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(n==pow(2,i))
		{
			cout << n-2;
			return 0;
		}
	}
	sort(a+1,a+1+n,cmp);
	cout << a[2];
	return 0;
}
