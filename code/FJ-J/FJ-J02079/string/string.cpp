#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200000],b[200000];
	int n,num = 0;
	cin >> n;
	for (int i = 0;i <= n;i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	for (int i = 0;i <= n;i++)
	{
		if (b[i] != b[n - i])
		{
	        b[n - i] = b[i];
	        num += a[n - i];
		}
	}
	cout << num; 
}
