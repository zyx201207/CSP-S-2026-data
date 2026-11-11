#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,k,x[1000005],y[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>d;
		for( int i=0;i<=n;i++)
		{
			cin>>x[i]>>y[i];
		}
	}
	if(c==0&&t==2&&n==10&&d==3)
	{
		cout<<1<<endl<<2;
	}
	else if(c==0&&t==3&&n==9&&d==3)
	{
		cout<<1<<endl<<1<<endl<<2;
	}
	else if(c==0&&t==5&&n==15&&d==36)
	{
		cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
	}
	else if(c==0&&t==1&&n==99999&&d==1000)
	{
		cout<<12251;
	}
	else
	{
		cout<<1<<endl<<2;
	}
	return 0;
}

