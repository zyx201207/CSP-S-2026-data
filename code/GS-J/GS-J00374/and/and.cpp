#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin)
	freopen("and.out","w",stdout)
	int n,m,a;
	cin >> n >> m;
	if(n >= m)
	{	
		if (n == 1 && m == 1)
		{
			cin >> a;
			cout << a;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				cin >> a;
			}
			cout << a;
		}
	}
	else
	{
		cout << "-1";
	}
	return 0;
}
