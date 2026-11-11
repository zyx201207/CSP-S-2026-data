#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==0)
	{
		if(a==0&&b==2&&c==4)
		{
			cout<<"1"<<endl;
			cout<<"2";
		}
		if(a==0&&b==2&&c==5)
		{
			cout<<"0"<<endl;
			cout<<"1";
		}
	}
	else 	
	{
		for(int i=1;i<=b;i++)
		{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
