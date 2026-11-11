#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100],num;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if a[i]==a[i]
		{
			num++;
		}
	}
	cout << num;
	return 0;
}
