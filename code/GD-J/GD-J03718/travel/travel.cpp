#include<iostream>
using namespace std;
char ans[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[5],s1[5],c2[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	int pd=1;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			pd=0;
		}
	}
	ans[0]=pd+'0';
	if(pd)
	{
		pd=1;
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i])
			{
				pd=0;
			}
		}
	}
	ans[1]=pd+'0';
	if(pd)
	{
		if((s1[2]<'D' && s2[2]<'D') || (s1[2]>'C' && s2[2]>'C'))
		{
			pd=1;
		}
		else
		{
			pd=0;
		}
	}
	ans[2]=pd+'0';
	if(pd)
	{
		if((s1[2]+1==s2[2]) || (s2[2]+1==s1[1]))
		{
			pd=1;
		}
		else
		{
			pd=0;
		}
	}
	ans[3]=pd+'0';
	cout<<ans;
	return 0;
}
/*
02 01A 02 01B
1111
02 01C 02 01A
1110
02 01C 02 01D
1100
02 02B 02 01A
1000
02 01A 03 01A
0000
11 09C 02 08B
0000
*/
