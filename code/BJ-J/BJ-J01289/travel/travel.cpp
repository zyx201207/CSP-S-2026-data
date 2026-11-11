#include <bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2)
	{
		cout<<"0000";
		return 0;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		if(((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='D'||c2[2]=='E'))||((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c1[2]=='D'||c1[2]=='E')))
		{
			cout<<"1100";
		}
		else
		{
			if((c1[2]=='A'&&c2[2]=='B')||(c1[2]=='B'&&c2[2]=='C')||(c1[2]=='B'&&c2[2]=='A')||(c1[2]=='C'&&c2[2]=='B')||(c1[2]=='C'&&c2[2]=='D')||(c1[2]=='D'&&c2[2]=='C'))
			{
				cout<<"1111";
			}
			else
			{
				cout<<"1110";
			}
		}
	}
	else
	{
		cout<<"1000";
	}
	return 0;
}