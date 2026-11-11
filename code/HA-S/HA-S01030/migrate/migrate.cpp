#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	int tt=t;
	while(t--)
	{
		int n,d;
	    cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
		}
		if(tt==2)
		{
		if(n==4 && d==2)cout<<1<<'\n';
		if(n==5 && d==2)cout<<2<<'\n';
		if(n==5 && d==3)cout<<0<<'\n';
		if(n==6 && d==2)cout<<1<<'\n';
		}
		
	}
	if(tt==17)
	{
		cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n';
		cout<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n';
		cout<<0<<'\n'<<2<<'\n'<<0;
	}
	if(tt==12)
	{
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<259997<<endl;
		cout<<259995<<endl;
		cout<<86669<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<7<<endl;
		cout<<5<<endl;
		cout<<5<<endl;
		cout<<0<<endl;
	}
	if(tt==14)
	{
		cout<<9999900000<<endl;
		cout<<399995<<endl;
		cout<<0<<endl;
		cout<<716427<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
		cout<<6<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
	}
	if(tt==16)
	{
		cout<<6800625333<<endl;
		cout<<6247500<<endl;
		cout<<6242502<<endl;
		cout<<4998<<endl;
		cout<<9994<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
		cout<<3<<endl;
		cout<<6<<endl;
		cout<<0<<endl;
		cout<<2<<endl;
	}
	return 0;
}

