#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if (r1!=x1)
	{
		cout<<"0000";
		return 0;
	}
	string rp=r2.substr(0,2);
	string xp=x2.substr(0,2);
	char rz=r2[2],xz=x2[2];
	if (rp!=xp)
	{
		cout<<"1000";
		return 0;
	}
	bool a=(rz<='C' && xz<='C'),b=(rz>'C' && xz>'C');
	if (!(a || b))
	{
		cout<<"1100";
		return 0;
	}
	if ((rz=='A' && xz=='C') || (rz=='C' && xz=='A'))
		cout<<"1110";
	else
		cout<<"1111";
	return 0;
}
