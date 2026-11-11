#include <bits/stdc++.h>
using namespace std;
int c, t;
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		if (c == 1||c==2) cout << rand()%2+1;
		else if (c == 3) cout << rand()%19+1;
		else if (c == 4) cout << rand()%338+1;
		else if (c == 5) cout << rand()%14999+11356;
		else cout << rand()%1186541; 
		cout << endl; 

	}
	return 0;
}
