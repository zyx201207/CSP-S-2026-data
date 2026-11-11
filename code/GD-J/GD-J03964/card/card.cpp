#include <iostream>
using namespace std;
int a[500005],seat[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		seat[a[i]] = i;
	}
	for (int i = 1;i <= m;i++)
	{
		int ans = 0;
		cout << n << " ";
	}
	return 0;
}
