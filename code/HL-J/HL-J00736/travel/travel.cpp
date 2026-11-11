#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<"1";
		if(a2[0]==b2[0]&&a2[1]==b2[1])
	{
		cout<<1;
		if(a2[2]-'A'<=3&&b2[2]-'A'<=3)
		{
		cout<<"1";
		int n=a2[2]-'A',m=b2[2]-'A';
	int q=max(n,m);
	int w=min(n,m);
	if(q-w==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
}
	else
	{
		cout<<"00";
	}
}
	else
	{
		cout<<"000";
	}
}
	else
	{
		cout<<"0000";
	}
	return 0;
}