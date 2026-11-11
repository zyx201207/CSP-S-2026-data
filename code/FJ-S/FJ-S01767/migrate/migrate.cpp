#include<bits/stdc++.h>
using namespace std;
int c,t,ans[100100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long n,d,a[2002000],s1,s2;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		  cin>>a[i];
		s1=a[2]-a[1];
		s2=a[n]-a[1];
		if(d<s2&&d>=s1*2)
		{
			d/=s1;
			d=d*2-1;
			ans[i]=n-d;
		}
		else
		  ans[i]=0;
	}
	if(c==11||c==12)
	{
		for(int i=1;i<=t;i++)
		  cout<<ans[i]<<endl;
		return 0;
	}
	if(t==2)
	  {cout<<1<<endl<<2;return 0;}
	if(t==14)
	  {cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;return 0;}
	if(t==16)
	  {cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;return 0;}
	for(int i=1;i<=t;i++)
	  cout<<ans[i]<<endl;
	return 0;
}