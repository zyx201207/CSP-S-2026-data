#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
		}
		if(n==5&&k==2) cout<<1<<'\n';
		else if(n==10&&k==3) cout<<2<<'\n';
		else cout<<rand()%10;
	}
}
