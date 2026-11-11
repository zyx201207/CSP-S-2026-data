#include<iostream>
using namespace std;
string c1,s1,c2,s2; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char a=s1[0],b=s1[1];
	char c=s2[0],d=s2[1];
	int as1=(a-'0')*10+(b-'0');
	int as2=(c-'0')*10+(d-'0');
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else if(c1==c2)
	{
		if(as1==as2)
		{
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
			{
				if(s1[2]=='A'&&s2[2]=='B')
				{
					cout<<"1111";
				}
				else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))
				{
					cout<<"1111";
				}
				else if(s1[2]=='C'&&s2[2]=='B')
				{
					cout<<"1111";
				}
				else if(s1[2]=='D'&&s2[2]=='F')
				{
					cout<<"1111";
				}
				else if(s1[2]=='F'&&s2[2]=='D')
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}	
	}
}
