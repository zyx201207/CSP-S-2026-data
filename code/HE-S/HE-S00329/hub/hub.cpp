#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--)
	{
		int n,k;
		cin>>n>>k;
		for (int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		int m=(n+1)/2;
		if ((m-k)%4==0)
			cout<<(m-k)/4+1<<"\n";
		else cout<<(m-k)/4+2<<"\n";
	}
	return 0;
}
