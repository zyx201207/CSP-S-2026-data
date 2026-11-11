#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[200005];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		sort(a,a+n,cmp);
		cout << a[0];
	}
	long long maxn = -1;
	for(int i = 1;i < m;i++)
	{
		for(int j = 0;j < n-i;j++)
		{
			maxn = (maxn,a[j] & a[j+i]);
		}
	}
	cout << maxn;
	return 0;
}
