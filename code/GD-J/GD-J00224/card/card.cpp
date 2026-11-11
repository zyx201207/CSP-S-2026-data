#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	if(m == 1)
	{
		for(int i = 1;i <= n;i++)
		{
			cout << n << " ";
		}
		return 0;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{				
			cout << 1 << " ";
		}
		return 0;
	}
	return 0;
}
