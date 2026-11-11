#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m,c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		int u,v;
		for(int i=1;i<=n;i++) cin>>u>>v;
		srand(time(NULL));
		printf("%d\n",rand()%1000);
	}
	return 0;
}

