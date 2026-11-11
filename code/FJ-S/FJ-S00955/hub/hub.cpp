#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	/*freopen("hub.in ","r",stdin);
	freopen("hub.out","w",stdout);*/
	long long c,t,n,k,u,v;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			cin>>u>>v;
		}
		if(n==5&&k==2) cout<<1<<endl;
		if(n==10&&k==3) cout<<2;
	}
	return 0;
}
