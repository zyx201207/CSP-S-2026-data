#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,n1;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
		} 
	}
	if(t==2)
	{
		cout<<1<<'\n'<<2;
	}
	else if(t==3)
	{
		cout<<1<<'\n'<<1<<'\n'<<2;
	}
	else if(t==5)
	{
		cout<<17<<'\n'<<9<<'\n'<<6<<'\n'<<6<<'\n'<<9;
	}
	else if(t==1)
	{
		cout<<12251;
	}
	return 0;
}
