#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6+10;
long long a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout << i << " ";
	}
	return 0;
}
