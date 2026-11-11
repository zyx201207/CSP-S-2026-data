#include<bits/stdc++.h>
using namespace std;
int c1,c3;
char c[20]; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>c[1]>>c[2]>>c[3]>>c3>>c[4]>>c[5]>>c[6];
	if(c1==c3&&c[1]!='01'&&c3!='16')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	 } 
    if(c[1]==c[4]&&c[2]==c[5])
    {
    	cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((c[3]=='D'&&c[6]!='C')||(c[3]=='C'&&c[6]=='D'))
	{
		cout<<"00";
		return 0;
	}
	else
	{
		cout<<"1";
		
	}
	if(c[3]=='C'&&c[6]=='A'||c[3]=='A'&&c[6]=='C')
	{
		cout<<"0";
	}
	else
	{
		cout<<"1";
		return 0;
	}
}
