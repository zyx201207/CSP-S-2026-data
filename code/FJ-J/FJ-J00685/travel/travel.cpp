#include<bits/stdc++.h>
using namespace std;
string p[5],q[5],n[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2,j;
	if(a1==a2)
	{
		for(int i=0;i<5;i++)
		{
			p[i]=b1[i];
			q[i]=b2[i];
		}
		if(p[0]==q[0] && p[1]==q[1])
		{
			n[0]=p[2];
			n[1]=q[2];
			sort(n[0],n[1]);
			if(n[1]=n[0]+1){
				if(n[0]=='A' || n[0]=='B' || n[0]=='D')
				j='1111';
				else j='1100';
			}
			else if(n[1]=n[0]+2)
			{
				if(n[0]=='A')
				j='1110';
				else j='1100';
			}
			else j='1100';
		}
	}
	else j='0000';
	cout<<j;
	return 0;
}
