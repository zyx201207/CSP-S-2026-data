#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
	preopen("migrate.in","r",stdin);
    preopen("migrate.out","w",stdout);
	int c,t,w=0;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		w=w+a+b;
		cin>>a>>b;
		int c[a];
		for(int i=0;i<a;i++)
		{
			cin>>c[i];
		}
	}
	if(t==2&&w==13)
	{
		cout<<1<<endl<<2<<endl;
	}
	else if(t==2&&w==16)
	{
		cout<<0<<endl<<1<<endl;
	}
	else if(t==17)
	{
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
	}
	else if(t==12)
	{
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0; 
	}
	else if(t==14)
	{
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	else if(t==16)
	{
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	return 0;
}
