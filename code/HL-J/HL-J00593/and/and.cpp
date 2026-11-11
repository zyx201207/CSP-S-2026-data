#include<bits/stdc++.h>
using namespace std;

int m,n;
int a[10000000];
int s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(i == m)
		{
			cout << a[i];
		}
	}
	return 0;
} 
