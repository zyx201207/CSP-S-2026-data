#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long a[n+5]={0},b[n+5]={0};;
	cin >> a[1];
	for(int i= 2;i <= n;i++)
	{
		cin >> a[i];
		b[i] =(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	for(int i= n;i >=1;i--)
	{
		if(b[i] <= m)
		{
			cout << i;
			return 0;
		}
	//\	cout << 0;
	}
	//cout << n;
	return 0;
}
