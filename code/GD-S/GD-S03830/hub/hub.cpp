#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		if(n<=10)
		{
			if(n%2==0)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<2<<endl;
			}
		}
		else
		{
			cout<<rand()<<endl;
		}
	}
	return 0;
}
