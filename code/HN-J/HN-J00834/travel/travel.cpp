#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int a[105][105];
char h,k;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>h>>x>>y>>k;
	if(n==x)
	{
		cout<<'1';
		if(m==y)
		{
			cout<<'1';
			if(h<='C'&&k<='C'||h>'C'&&k>'C')
			{
				cout<<'1';
				if(h-k==1||k-h==1||h=='D'&&k=='F'||h=='F'&&k=='D')
				{
					cout<<'1';
				}
				else
				{
					cout<<'0';
				}
			}
			else
			{
				cout<<'0'<<'0';
			}
		}
		else
		{
			cout<<'0'<<'0'<<'0';
		}
	}
	else
	{
		cout<<'0'<<'0'<<'0'<<'0';
	}
	return 0;
}
