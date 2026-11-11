#include <bits/stdc++.h>
using namespace std;
int main()
{
	string c1[2],s1[3],c2[2],s2[3];
	for(int i=1;i<=2;i++)
	{
		cin>>c1[i];
	}for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}for(int i=1;i<=2;i++)
	{
		cin>>c2[i];
	}for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1[1]==c2[1]&&c1[2]==c2[2])
	{
		cout<<"1";
		if(s1[1]==s2[1]&&s1[2]==s2[2])
		{
			cout<<"1";
			if(((s1[3]=="A"||s1[3]=="B"||s1[3]=="C")&&(s2[3]=="A"||s2[3]=="B"||s2[3]=="C"))||((s1[3]=="F"||s1[3]=="G")&&(s2[3]=="F"||s2[3]=="G")))
			{
				cout<<"1";
				if((((s1[3]=="B")&&(s2[3]=="A"||s2[3]=="C"))||((s1[3]=="F"||s1[3]=="G")&&(s2[3]=="F"||s2[3]=="G"))||(s1[3]=="A"&&s2[3]=="B")||(s1[3]=="C"&&s2[3]=="B")))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
    return 0;
}
