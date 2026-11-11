#include <bits/stdc++.h>
using namespace std;
long long m[20],n[20];
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c&&b==d)
	{
		cout<<"1111";
		return 0;
	}
	if(a==c)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	long long x=b.size(),y=d.size();
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			if(m[1]==n[1]&&m[2]==n[2])
			{
				cout<<'1';
			}
			else
			{
				cout<<'0';
			}
			if(m[1]==n[1]&&m[2]==n[2]&&m[3]==n[3])
			{
				cout<<'1';
			}
			else
			{
				cout<<'0';
			}
			if(m[1]-'0'*10+1+m[2]-'0'==n[1]-'0'*10+n[2]-'0'||m[1]-'0'*10-1+m[2]-'0'==n[1]-'0'*10+n[2]-'0')
			{
				cout<<'1';
			}
			else
			{
				cout<<'0';
			}
		}
	 }
	
	return 0;
}
