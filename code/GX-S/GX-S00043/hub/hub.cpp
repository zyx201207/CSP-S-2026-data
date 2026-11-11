#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	scanf("%d%d",&c,&t);
	for(int T=0;T<t;T++)
	{
		scanf("%d%d",&n,&k);
		vector< vector<int> > cs(n+1,vector<int>());
		for(int f=0,u,v;f<n-1;f++)
		{
			scanf("%d%d",&u,&v);
			cs[u].push_back(v);
			cs[v].push_back(u);
		}
		printf("%d\n",max(1,n-k-4));
	}
	return 0;
}
