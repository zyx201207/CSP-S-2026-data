#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,a,b;
	char c1,c2;
	cin>>n>>a>>c1>>m>>b>>c2;
	if(n==m)
	{
		cout<<1;
		if(a==b)
		{
			cout<<1;
			if(c1<='C'&&c2<='C')
			{
				cout<<1;
				if(int(c1)==int(c2)-1)
				{
					cout<<1;
				}
				else if(int(c1)-1==int(c2))
				{
					cout<<1;
				}
				else cout<<0;
			}
			else if(c1>='D'&&c2>='D')
			{
				cout<<1;
				if(int(c1)==int(c2)-1)
				{
					cout<<1;
				}
				else if(int(c1)-1==int(c2))
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
