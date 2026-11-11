#include<bits/stdc++.h>
using namespace std;

bool check(char x,char y)
{
	int a = 1,b = 1;
	if(x=='D' || x=='E') a = 2;
	if(y=='D' || y=='E') b = 2;
	return a == b;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2) cout<<"0000";
	else
	{
		//1xxx
		int r1 = s1[0]*10+s1[1];
		int r2 = s2[0]*10+s2[1];
		if(r1 != r2) cout<<"1000";
		else
		{
			//11xx
			if(!check(s1[2],s2[2])) cout<<"1100";
			else
			{
				//111x
				if(abs(s1[2]-s2[2]) != 1) cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}
