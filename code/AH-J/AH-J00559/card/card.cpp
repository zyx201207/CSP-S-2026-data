#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005];
int main()
{
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	int uo = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		
		if (i == n - 1)
		{
			uo = a[i];
			
		}
	}
	b[uo] = n; 
	for (int i = 0;i < m;i++)
	{
		
		cout << b[i] << " ";
	}
	return 0;
}
