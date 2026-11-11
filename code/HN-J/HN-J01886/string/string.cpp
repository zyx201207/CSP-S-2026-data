#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,si,k = 0,sum = 0;
	char s[300000],sl,sk[150000];
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> si;
		cin >> sl;
		for (int i = k;i < k + si; i++)
		{
			s[i] = sl;
		}
		k += si;
	}
	int f = 0;
	if (k % 2 == 1)
	{
		f = k / 2 - 1;
	}
	else
	{
		f = k / 2 - 1;
	}
	for (int i = 0;i <= f;i++)
	{
		if (s[i] != s[k - i - 1])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
