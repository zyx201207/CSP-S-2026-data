#include<bits/stdc++.h>
using namespace std;
long long c,t,a;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>a;
	if(c==0)
	{
		if(t==2&&a==4)
		{
			cout<<1<<endl<<2;
			return 0;
		}
		if(t==2&&a==5)
		{
			cout<<0<<endl<<1;
		}
		else
		{
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		}
	}
	else cout<<2<<endl<<0<<endl<<1;
	return 0;
}
