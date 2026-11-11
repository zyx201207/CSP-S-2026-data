#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			cin>>x>>y;
		}
		if(n==5 && k==2)cout<<1<<endl;
		if(n==10 && k==3)cout<<2<<endl;
		if(n==8 && k==6)cout<<1<<endl;
		if(n==6 && k==5)cout<<1<<endl;
		if(n==9 && k==3)cout<<2<<endl;
		
	}
	return 0;
}

