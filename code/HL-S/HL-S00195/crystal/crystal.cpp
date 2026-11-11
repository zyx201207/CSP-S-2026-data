#include <bits/stdc++.h>
using namespace std;
int n;
int num(int x,int s)
{
	int r=1;
	for (int i = 1;i <= s;i++)
	{
		r+=x;
	}
	return r;
}
long long m,a[100005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if((a[1]-a[2] == a[2]-a[3]) || (n==2))
	{
		int x = max(a[1] - a[2],a[2] - a[1]),y = 0,i = 0;
		while(y<=m)
		{
			i++;
			y += num(x,i);
		}
		cout << i+1;
	}
	return 0;
} //等差数列偏分代码 
