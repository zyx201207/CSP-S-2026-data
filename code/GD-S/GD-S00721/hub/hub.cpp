#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n,k;
vector<int> g[N]; 
int vis[N];
void solve()
{
	cin >> n >> k;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout << (n+1)/2 - (k+1)/2 << "\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
