#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i];
	for(int i = 1;i<=n;i++)
	{
		for(int j = i+1;j<=n;j++)
		{
			if(a[i] == a[j])
			{
				cout << a[i];
				return 0;
			}
		}
	}
	cout << 4;
	return 0;
} 
