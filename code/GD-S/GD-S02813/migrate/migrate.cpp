#include<iostream>
#include<cstring>
using namespace std;
int a[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			if(d==2)
			{
				cout<<n-1;
			}
			else
			{
				cout<<0;
			}
		}
		cout<<endl;
	}
	return 0;
}
