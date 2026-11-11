#include<bits/stdc++.h>
using namespace std;
string s1, c1, s2, c2;
char seat[5]={'A', 'B', 'C', 'D', 'F'};
bool cmpside(char a, char b)
{
	int side1=1, side2=1;
	for(int i=0; i<3; i++)
	{
		if(seat[i]==a)
		{
			side1=0;
		}
		if(seat[i]==b)
		{
			side2=0;
		}
	}
	return (side1==side2);
}
bool near(char a, char b)
{
	int p1, p2;
	for(int i=0; i<5; i++)
	{
		if(seat[i]==a)
		{
			p1=i;
		}
		if(seat[i]==b)
		{
			p2=i;
		}
	}
	if(p1>p2)
	{
		swap(p1, p2);
	}
	return (p2-p1==1);
}
string anss="0000";
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		anss[0]='1';
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			anss[1]='1';
			if(cmpside(s1[2], s2[2]))
			{
				anss[2]='1';
				if(near(s1[2], s2[2]))
				{
					anss[3]='1';
				}
			}
		}
	}
	cout<<anss<<"\n";
	return 0;
}
//Trick||Treat!Trick||Treat!Trick||Treat!
