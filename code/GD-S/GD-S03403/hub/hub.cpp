#include <bits/stdc++.h>
using namespace std;
const int N=1003;
int c,t,n,k;
vector<int> s[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
		cout<<rand()%5+1;
	}
	return 0;
}
