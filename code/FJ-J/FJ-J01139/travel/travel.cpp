#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c) 
	{
		cout<<"0000"<<endl;
		return 0;
	}
    if(b[0]+b[1]!=d[0]+d[1])
	{
		cout<<"1000"<<endl;
		return 0;
	}
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='E'))
	{
		cout<<"1100"<<endl;
		return 0;
	}
	if((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='E'))
	{
		cout<<"1100"<<endl;
		return 0;
	}
	if(abs(int(b[2])-int(d[2]))==1)
	{
		if(b[2]=='C'&&d[2]=='D') 
		{
			cout<<"1110"<<endl;
			return 0;
		}
		if(b[2]=='D'&&d[2]=='C') 
		{
			cout<<"1110"<<endl;
			return 0;
		}
		else 
		{
			cout<<"1111"<<endl;
			return 0;
		}
	}
	else if((b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F'))
	{
		cout<<"1111"<<endl;
		return 0;
	}
	else cout<<"1110"<<endl;
	return 0; 
}
