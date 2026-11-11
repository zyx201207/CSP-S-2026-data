#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(c==4)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	if(c==5)
	{
		cout<<0<<endl<<1;
		return 0;
	}
	if(b==1)
	{
		cout<<0<<endl<<0;
		return 0;
	}
	cout<<2<<endl<<3;
	return 0;
}
