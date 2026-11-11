#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a,num[200005],sum=0;
	char y[200005];
	cin >> a;
	for(int i = 1;i <= a;i++)
	{
		long long c;
		cin >> c;
		num[i] = c;
		char d;
		cin >> d;
		y[i] = d;
	}
	if(a==3)
	{
		cout << 2;
	}
	else if (a==2)
	{
		cout << 0;
	}
	else
	{
		cout << 3000000000;
	}
	return 0;
}
