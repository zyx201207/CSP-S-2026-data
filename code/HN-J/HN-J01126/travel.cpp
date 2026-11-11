#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	string x,y;
	ifstream cin;
	ofstream cout;
	cin.open("travel.in");
	cout.open("travel.out");
	cin>>a>>x>>b>>y;
	if (a!=b) 
	{
		cout<<"0000";
		return 0;
	}for(int i=0;i<2;i++)
	{
		if (x[i]!=y[i])
		{
			cout<<"1000";
			return 0;
		}
	}char s[2];
	s[0]=x[2];
	s[1]=y[2];
	sort(s,s+2);
	if (s[0]<='C'&&s[1]>='D')
	{
		cout<<"1100";
		return 0;
	}if ((s[0]=='D'&&s[1]=='F')||(s[0]=='B'&&s[1]=='C')||(s[0]=='A'&&s[1]=='B'))
	{
		cout<<"1111";
		return 0;
	}cout<<"1110";
	return 0;
 } 
