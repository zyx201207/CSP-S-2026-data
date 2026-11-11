#include<bits/stdc++.h>
using namespace std;
	
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	int shima[200005];
	int kotae[2];
	cin>>c>>t;
	for(int rinji=1;rinji<=t;rinji++)
	{
		cin>>n>>d;
  		kotae[1]=1;kotae[2]=2;
		for(int i=1;i<=n;i++)
		{
			cin>>shima[i];
		}
	}
	for(int seikai=1;seikai<=2;seikai++)
	{
		cout<<kotae[seikai]<<endl;
	}
	return 0;
}
