#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200002];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	cout << n*(n+1)/2;
}
