#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
// freopen("and.in","r",stdin)£»
// freopen("and.out","w",stdout); 
	int n, m;
	cin >> n >> m;
	int p = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int j2 = 1; j2 <= n; j2++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[j] <= a[j+1])
			{
				p = a[j];
				a[j] = a[j+1];
				a[j+1] = p;
			}
		}	
	}
	cout << a[m];
	return 0;
}
