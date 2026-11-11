#include <bits/stdc++.h>
using namespace std;
int a[500005],x[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.in","r",stdin);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i]; 
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
			x[a[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout << x[i] << " ";
	return 0;
}
