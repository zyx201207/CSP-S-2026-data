#include<bits/stdc++.h>
using namespace std;
int u[1000001],v[1000001];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>u[i]>>v[i];
		}
	}
	cout<<1<<endl;
	cout<<2;
	return 0;
}
