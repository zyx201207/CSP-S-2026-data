#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2) cout<<1;
	else  
	{
		cout<<"0000";
		return 0;
	}
	string p1 = s1.substr(0,2),p2 = s2.substr(0,2);
	if(p1 == p2) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	char z1 = s1[2],z2 = s2[2];
	if(z1 == 'A'||z1 == 'B'||z1 == 'C')
	{
		if(z2 == 'A'||z2 == 'B'||z2 == 'C') cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	{
		if(z2 == 'D'||z2 == 'F') cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	if(z1 == 'A'||z1 == 'B'||z1 == 'C')
	{
		if(abs(int(z1-z2)) == 1) cout<<1;
		else cout<<0;
	}
	else
	{
		if(z2 == 'D'||z2 == 'F') cout<<1;
		else cout<<0;
	}
	return 0;
}
