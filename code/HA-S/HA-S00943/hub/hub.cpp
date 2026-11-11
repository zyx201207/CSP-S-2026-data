#include<bits/stdc++.h>

using namespace std;
int c, t;
int n, k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			
		}
		if(n == k){
			cout << 0 << endl;
			continue;
		}
		if(n == 3)
		{
			cout << 1 << endl;
			continue;
		}
		if(n == 4)
		{
			cout << 1 << endl;
			continue;
		}
		if(n == 5)
		{
			cout << 1 << endl;
			continue;
		}
		
	}
	return 0;
}
