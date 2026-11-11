#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string a1,a2,b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b1[0]==b2[0]&&b1[1]==b2[1])  cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((b1[2]<='C'&&b2[2]<='C')||(b1[2]>='D'&&b2[2]>='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(int(b1[2])-int(b2[2]))==1) cout<<1;
	else cout<<0;
	return 0;
}
