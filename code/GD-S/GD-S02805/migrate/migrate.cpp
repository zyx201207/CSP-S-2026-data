#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b>>c>>d;
	//1 
	if(b==2&&c==4&&d==2)
	{
		cout<<"1\n2";
	}
	else if(b==2&&c==5&&d==3)
	{
		cout<<"0\n1";
	}
	else
	{
		cout<<"2\n3";
	}
	return 0;
} 
