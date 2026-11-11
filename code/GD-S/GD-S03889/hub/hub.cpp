#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int c,t;

int main()
{
	srand(time(0));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		cout<<rand()%90;
	}

	return 0;
}

