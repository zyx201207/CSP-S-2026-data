#include<bits/stdc++.h>
using namespace std;

int ans;

void check(string c1,string c2,string c3,string c4)
{
	if(c1==c3)
	{
		ans=1;
		if(c2[0]==c4[0]&&c2[1]==c4[1])
		{
			ans=11;
			if((((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c4[2]=='A'||c4[2]=='B'||c4[2]=='C'))||((c2[2]=='F'||c2[2]=='D')&&(c4[2]=='F'||c4[2]=='D')))&&c2[2]!=c4[2])
			{
				ans=111;
				if((((c2[2]=='F'||c2[2]=='D')&&(c4[2]=='F'||c4[2]=='D'))||((c2[2]=='A'&&c4[2]=='B')||(c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C'))||(c2[2]=='C'&&c4[2]=='B')))&&c2[2]!=c4[2])
					ans=1111;
				else
				{
					ans=1110;
				}
			}
			else
			{
				ans=1100;
			}
		}
		else
		{
			ans=1000;
		}
	}
	else
	{
		ans=0000;
	}
}

int main()
{
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	check(c1,c2,c3,c4);
	if(ans==0)
	{
		cout<<"0000";
	}
	else
	{
		cout<<ans;
	}
	return 0;
}
