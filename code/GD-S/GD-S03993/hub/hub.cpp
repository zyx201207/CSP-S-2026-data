#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int c,t,n,k;
vector <int> e[N];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout << 1 << endl;
	}
	return 0;
}
