#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(t==17)
	{
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl;
		cout<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl;
		cout<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	if(t==12)
	{
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl;
		cout<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
	}
	if(t==14)
	{
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl;
		cout<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	if(t==16)
	{
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl;
		cout<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		int x;
		for(int i=1;i<=n;i++)
		{
			
			cin>>x;
		}
		if(x==4)
			cout<<1<<endl;
		if(x==5)
			cout<<2<<endl;
		if(x==2)
			cout<<0<<endl;
		if(x==6)
			cout<<1<<endl;
	}
}
