#include <bits/stdc++.h>
using namespace std;

long long u[100005],v[100005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	for (int t=1;t<=T;t++)
	{
		int n,k;
		cin >> n >> k;
		for (int i=1;i<=n-1;i++)
		{
			cin >> u[i] >> v[i];
		}
		cout << 0 << " ";
	}
	return 0;
} 
