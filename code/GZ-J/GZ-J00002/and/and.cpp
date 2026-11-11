// GZ-J00002 утсю╨Г 
#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	int a[n+5],b[n+5];
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	if(m ==1)
	{
		cout << max(a[0],a[n]);
		return 0;
	}
	for(int i =0;i<n;i++)
	{
		for(int j =i;j<n;j++)
		{
			b[i] = a[i] && a[j];
		}
	}
	cout << max(b[0],b[n]);
	return 0;
}
