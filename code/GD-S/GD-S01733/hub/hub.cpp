#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int c , t , n , k , a[N];
vector<pair<int , int> > vc;

int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int u , v;
			cin >> u >> v;
			vc.push_back({u , v});
		}
	}
	
	
	return 0;
}
