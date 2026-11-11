#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,r1,c2,r2;
	cin>>c1>>r1>>c2>>r2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(!(r1[0]==r2[0]&&r1[1]==r2[1]))
	{
		cout<<"1000";
		return 0;
	}
	if(r1[2]<='C'&&r2[2]<='C')
	{
		if(abs(r1[2]-r2[2])==1) cout<<"1111";
		else cout<<"1110";
	}
	else if(r1[2]>='D'&&r2[2]>='D') cout<<"1111";
	else cout<<"1100";
	return 0;
}
/*
01 11A 01 12B
01 11A 01 21B
01 21A 01 12B
01 11A 01 11B
*/
