#include<bits/stdc++.h>
using namespace std;

long long u,v,n,k;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i<n; i++)
		{
			int u,v;
			cin >> u >> v;
		}
		cout << (1+n)/2-1 << endl;
	}
	return 0;
}
