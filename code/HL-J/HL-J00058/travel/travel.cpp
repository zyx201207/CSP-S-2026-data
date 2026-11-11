#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","Y",stdin);
	freopen("travel.out","W",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!=01&&c1!=16&&c2!=01&&c2!=16)
	{
		cout<<"1";
		
	}
	else
	{
		cout<<"0000";
		
	}
	return 0;
}
