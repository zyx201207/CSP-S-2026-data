#include <Bits/stdc++.h>>
using namespace std;
string s1,s2,s3,s4;
int main()
{
	freopen(travel.app,"r",stdin);
	freopen(travel.out;"w";stdout);
	cin>>s1>>s2>>s3>>s4;
	bool a=1,b=1,c=1,d=1;
	for(int i=0;i<s1.size()&&i<s3.size();i++)
	{
		if(s1[i]!=s3[i])
			a=0;
	}
	for(int i=0;i<2;i++)
		if(s2[i]!=s4[i])
			b=0;
	if(s2[2]>s4[2])
	{
	
		if(s2[2]-s4[2]>2)
			c=0;
		if(s2[2]-s4[2]>1)
			d=0;
	}
	if(s2[2]<s4[2])
	{
	
		if(s4[2]-s2[2]>2)
			c=0;
		if(s4[2]-s2[2]>1)
			d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
