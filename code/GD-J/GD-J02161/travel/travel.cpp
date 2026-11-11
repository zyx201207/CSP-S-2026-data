#include<bits/stdc++.h>
using namespace std;
struct zw
{
	int p,z;
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ac,az,bc,bz;
	int a1,b1;
	zw b2,a2;
	cin>>ac>>az>>bc>>bz;
	if(ac[0]==1)
	{
		a1+=10;
	}
	a1+=(ac[1]-'0');
	if(bc[0]==1)
	{
		b1+=10;
	}
	b1+=(bc[1]-'0');
	if(az[0]==1)
	{
		a2.p+=10;
	}
	a2.p+=(az[1]-'0');
	a2.z=(az[2]-'A');
	if(bz[0]==1)
	{
		b2.p+=10;
	}
	b2.p+=(bz[1]-'0');
	b2.z=(bz[2]-'A');
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	if(a2.p!=b2.p)
	{
		cout<<"1000";
		return 0;
	}
	if(a2.z<=3&&a2.z>=1&&b2.z>=4&&b2.z<=6)
	{
		cout<<"1100";
		return 0;
	}
	if(abs(a2.z-b2.z)==2)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
