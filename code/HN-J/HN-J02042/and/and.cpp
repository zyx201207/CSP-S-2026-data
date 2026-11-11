#include <iostream>
#include <algorithm>
using namespace std;

bool a[50],b[50],c[50];
long long aa[1000010];

long long a_and_b(long long a1,long long b1)
{
	int i1 = 1,j1 = 1;
	while(a1 != 0)
	{
		a[i1] = a1 % 2;
		a1 /= 2;
		i1++;
	}
	while(b1 != 0)
	{
		b[j1] = b1 % 2;
		b1 /= 2;
		j1++;
	}
	i1 -= 1;
	j1 -= 1;
	for(int i = 1; i <= max(i1,j1); i++)
	{
		if(a[i] == b[i])
		{
			c[i] = a[i];
		}
		else
		{
			c[i] = 0;
		}
	}
	long long cc = 0;
	for(int i = max(i1,j1); i >= 1; i--)
	{
		cc = cc * 2 + c[i]; 
	}
	return cc;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a2,b2,maxn = -1e9;
	cin >> a2 >> b2;
	for(int i = 1; i <= a2; i++)
	{
		cin >> aa[i];
		maxn = max(maxn,aa[i]);
	}
	if(b2 == 1)
	{
		cout << maxn << endl;
		return 0;
	}
	if(b2 == 2)
	{
		maxn = -1e9;
		for(int i = 1; i <= a2; i++)
		{
			for(int j = 1; j <= a2; j++)
			{
				maxn = max(maxn,a_and_b(aa[i],aa[j]));
			}
		}
		cout << maxn << endl;
	}
	return 0;
}
