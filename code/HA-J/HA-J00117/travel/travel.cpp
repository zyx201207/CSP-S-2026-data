#include <bits/stdc++.h>
using namespace std;
struct ic
{
	int n;
	char a[3];
};
int main(int argc, char** argv)
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ic x,r;
	cin>>r.n>>r.a>>x.n>>x.a;
	if(r.n==x.n)
	{
		cout<<1;
		if(r.a[1]==x.a[1]&&r.a[0]==x.a[0])
		{
			cout<<1;
			if((r.a[2]<='C'&&x.a[2]<='C')||(r.a[2]>'C'&&x.a[2]>'C'))
			{
				cout<<1;
				if(r.a[2]+1==x.a[2]||r.a[2]-1==x.a[2])
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
