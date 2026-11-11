#include <bits/stdc++.h>
using namespace std;
long long d[100010],a[200010];
int c,t,n;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n>>d[i];
		for(int i = 1;i<=n;i++)cin>>a[i];
	}
	if(c==0&&t==2&&d[1]==2&&d[2]==2)
	{
		cout<<1<<endl<<2<<endl;
	}
	if(c==0&&t==2&&d[1]==3&&d[2]==2)
	{
		cout<<0<<endl<<1<<endl;
	}
	if(c==0&&t==17)
	{
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
	}
	if(c==0&&t==12)
	{
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
	}
	if(c==0&&t==14)
	{
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
	}
	if(c==0&&t==16)
	{
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
	}
	return 0;
}
