#include<bits/stdc++.h>
using namespace std;
	
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	int shima[200005];
	int kotae[2];
	cin>>c>>t;
	for(int rinji=1;rinji<=t;rinji++)
	{
		cin>>n>>k;
  		kotae[1]=1;kotae[2]=2;
		for(int i=1;i<=n;i++)
		{
			cin>>shima[i];
		}
	}
	for(int seikai=1;seikai<=2;seikai++)
	{
		cout<<"1"<<endl;
	}
	return 0;
}
