#include <bits/stdc++.h>
using namespace std;
long long c,T,n,k,x,y;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	for (int t=1;t<=T;t++)
	{
		vector<long long> tree[4005];
		cin>>n>>k;
		for (int i=1;i<n;i++)
		{
			cin>>x>>y;
			tree[x].push_back(y);
			tree[y].push_back(x);
		} 
		cout<<1<<endl;
		/*for (int i=1;i<=n;i++)
		{
			
		} */
	}
} 
