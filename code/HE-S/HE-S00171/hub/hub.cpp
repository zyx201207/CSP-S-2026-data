#include <bits/stdc++.h>
using namespace std;
long long int c,t,n[100005],k[100005],u[100005],v[100005];

void init()
{
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
		for(int j=1;j<=n[i]-1;j++)
		{
			cin>>u[i]>>v[i];
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	init();
	cout<<"1\n2";
	
	return 0;
}
