#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,c;
	string b,d;
	bool a1=0,b1=0,c1=0,d1=0;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		a1=1;
		b1=1;
		c1=0;
		d1=0;
	}
	else
	{
		a1=0;
		b1=0;
		c1=0;
	}
	cout<<a1<<b1<<c1<<d1;
	
	return 0;
}
