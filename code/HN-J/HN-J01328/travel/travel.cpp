#include<bits/stdc++.h>
using namespace std;
bool x=true; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char s1[5],s2[5];
	int c1,c2;
	cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		x=false;
	}
	if(x==true&&(int)s1[1]==s2[1]&&(int)s1[2]==s2[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		x=false;
	}
	if(x==true && ((int)s1[3]<=67&&(int)s2[3]<=67 || (int)s1[3]>67&&(int)s2[3]>67))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		x=false;
	}
	if(x==true && abs((int)s1[3]-(int)s2[3])==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
