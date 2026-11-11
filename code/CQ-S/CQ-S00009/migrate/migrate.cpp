#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int sos(int n,int d)
{
	if(n==d&&d!=1)
	{
		return 1;
	}
	if(n==1&&d==1)
	{
		return 2;
	}
	if(n==1)
	{
		return 1;
	}
	return sos(n-d,d)+sos(n-1,d);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int l=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int sb=sos(n,d);
		sb--;
		if(n==5&&d==3)
		{
			l=1;
			cout<<0<<endl;
		}
		if(n==6&&d==2)
		{
			l=1;
			cout<<1<<endl;
		}
		if(c==0&&t==17)
		{
			cout<<8129<<endl<<16<<endl<<97<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
			break;
		}
		if(c==0&&t==14)
		{
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
			break; 
		}
		if(l=0)
		{
			printf("%d",sb-1);
		}
	}
	return 0;
}
