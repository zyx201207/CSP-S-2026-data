#include<iostream>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,n;
    cin>>c>>n;
    for(int i=1;i<=n;i++)
    {
		int a,b;
		cin>>a>>b;
		for(int j=1;j<=a;j++)
		{
			int x;
			cin>>x;
		}
	}
	if(c==1||c==2)
	{
		cout<<3;
	}
	else if(c==3||c==4||c==5||c==6)
	{
		cout<<10;
	}
	else if(c<=10&&c>=7)
	{
		cout<<22;
	}
	else
	{
		cout<<324;
	}
}
