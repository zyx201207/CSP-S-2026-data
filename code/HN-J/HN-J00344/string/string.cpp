#include <bits/stdc++.h>
using namespace std;
int n,a[10005],sum,r,l,k,t;
string s,p;
bool f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n == 1)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0;i < n;i++)
	{
		cin >> a[i] >> s[i];
		p += s[i];
	}
	if(n % 2 == 1)
	{
		k = n / 2 + 1;
	}
	else
	{
		k = n / 2;
	}
	for(int i = 0;i < n / 2;i++)
	{
		for(int j = k - 1;j >= 0;j--)
		{
			if(p[i] != p[j])
			{
				p[j] = p[i];
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
