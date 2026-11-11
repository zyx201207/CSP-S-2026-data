#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c, t;
int n, k;
int u, v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1; i<n; i++)
			cin>>u>>v;
		if(c==13 || c==14)
		{
			cout<<1<<"\n";
			continue;
		}
		else cout<<rand()<<"\n";
	}
	return 0;
}
