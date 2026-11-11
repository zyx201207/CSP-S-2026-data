#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;

	int a=c1[0];
	int b=c1[1];
	int c=c2[0];
	int d=c2[1];
	int q=s1[0];
	int w=s1[1];
	int e=s2[0];
	int r=s2[1];
	if(a==c && b==d)
	{
		cout<<"1";
		if(q==e && w==r)
		{
			cout<<"100";
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
	
}
