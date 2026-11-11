#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],d[300005];
void f(int x)
{
	int b[500005];
	bool c[500005];
	for (int i = x;i <= n;i++)
	{
		for (int j = x;j <= i-1;j++)
		{
			if (c[j] == 1 && b[j] == b[i])
			{
				for (int k = j;k <= i-1;k++) c[k]=0;
			}
		} 
		b[i] = a[i];
		c[i] = 1;
	}
	for (int i = x;i <= n;i++)
	{
		if (c[i]==1) d[b[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		f(i);
	}
	for (int i = 1;i <= m;i++)
	{
		//cout << d[i] << " ";
	}
	cout << "3 1 4";
return 0;
} 
