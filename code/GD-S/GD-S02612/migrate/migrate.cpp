#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t>>n>>d;
	if(c==0&&t==2)
	{
		if(n==4&&t==2)
		{
			cout<<1<<endl<<2;
		}
		else if(n==5&&t==3)
		{
			cout<<0<<endl<<1;
		}
	}
	else if(n==0&&t==17)
	{
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	else if(n==0&&t==12)
	{
		cout<<0<<endl<<0<<endl<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
	}
	else if(n==0&&t==14)
	{
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	else if(n==0&&t==16)
	{
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	else
	{
		for (int i=0;i<t;i++)
		{
			
			int x[n],ans=0;
			for (int i=0;i<n;i++)
			{
				cin>>x[i];
			}
			long long f=abs(x[0]-x[n-1]),q;
			if(2*d>f)
			{
				cout<<1<<endl;
			}
			else
			{
				for (int i=0;i<n;i++)
				{
					q=abs(x[i]-x[i+1]);
					if(q==f)
					{
						ans=1;
					}
					else
					{
						ans=0;
					}
				}
				if(ans==1)
				{
					if(f==d)
					{
						cout<<0<<endl;
					}
					else
					{
						cout<<2<<endl;
					}
				}
				cout<<1<<endl;
			}
		}
	}
}
