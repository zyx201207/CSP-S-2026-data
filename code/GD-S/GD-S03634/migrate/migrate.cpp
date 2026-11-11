#include<iostream>
using namespace std;

int c,t;
int	n,d;
int x[2000006];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int mind=x[2]-x[1];
		int t=d/mind;
		int ans=0;
		for(int i=1;i<t;i++)
		{
			if(t+i+1>n)
			{
				break;
			}
			ans+=n-t-i;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
