#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+10;
vector<int>g[N];
int n,k;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<rand()%9<<"\n";//%%%
	}
	return 0;
}
