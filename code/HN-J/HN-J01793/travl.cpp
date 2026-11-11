#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int b[3],d[3];
	char a,c;
	cin>>a;
	cin>>b[1]>>b[2]>>b[3];
	cin>>c;
	cin>>d[1]>>d[2]>>d[3];
	if(a==c)
	{
		cout<<1;
	}
	else{
		cout<<0;
		}
		if(b[1]==d[1] && b[2]==d[2])
		{
			cout<<1;
			if(b[3] && d[3])
			{
				cout<<11;
			}
			if(b[3] && d[3])
			{
				cout<<11;
			}
			if(b[3] && d[3])
			{
				cout<<11;
			}
				if(b[3] && d[3])
			{
				cout<<11;
			}
			if(b[3] && d[3])
			{
				cout<<11;
			}
			if(b[3] && d[3])
			{
				cout<<11;
			}
		else
		{
			if(b[3] && d[3])
			{
			cout<<1;
			}
			if(b[3] && d[3])
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}

