#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	bool x[5]={0};
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		x[1]=1;
	}
	else
	{
		x[1]=0;
	}
	if(x[1]==1&&c[0]==d[0]&&c[1]==d[1])
	{
		x[2]=1;
	}
	else
	{
		x[2]=0;
	}
	if(x[2]==1)
	{
		if(c[2]<='C'&&d[2]<='C')
		{
			x[3]=1;
		}
		else if(c[2]>'C'&&d[2]>'C')
		{
			x[3]=1;
		}
	}
	else
	{
		x[3]=0;
	}
	if(x[3]==1&&c[2]+1==d[2]||c[2]-1==d[2])
	{
		x[4]=1;
	}
	else
	{
		x[4]=0;
	}
	for(int i=1;i<=4;i++)
	{
		cout<<x[i];
	}
	return 0;
}

