#include<bits/stdc++.h> 
using namespace std;
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel,out","w",stdout);
	string cr,sr,cx,sx,da;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		
		if(sr[0]==sx[0]&&sr[1]==sx[1])
		{
			if(sr[2]+sx[2]=='D'+'F')
			{
				da+='1111';
			}
			if(sr[2]+sx[2]=='A'+'B')
			{
				da+='1111';
			}
			if(sr[2]+sx[2]=='B'+'C')
			{
				da+='1111';
			}
			if(sr[2]+sx[2]=='A'+'C')
			
			{
				da+='1110';
			}
			
			else
			{
				da+='1100';
			}
		}
		else
		{
			da+='1000';
		}
	}
	else
	{
		da+='0000';
	}
	cout<<da;
	return 0;
}
