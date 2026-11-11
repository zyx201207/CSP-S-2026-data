#include<bits/stdc++.h>
using namespace std;

char c1[10],s1[10],c2[10],s2[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(!(c1[0]==c2[0]&&c1[1]==c2[1]&&(c1[0]!='0'||c1[1]!='1')&&(c1[0]!='1'||c1[1]!='6')))	cout<<"0000"<<endl;
	else
	{
		cout<<"1";
		if(!(s1[0]==s2[0]&&s1[1]==s2[1]))	cout<<"000"<<endl;
		else
		{
			cout<<"1";
			if(!((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')))	cout<<"00"<<endl;
			else
			{
				cout<<"1";
				if(abs((s1[2]-'A')-(s2[2]-'A'))==1)	cout<<"1"<<endl;
				else	cout<<"0"<<endl;
			}
		}
	}
	return 0;
}
