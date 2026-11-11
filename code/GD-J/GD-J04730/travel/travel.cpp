#include<bits/stdc++.h>
using namespace std;
int a,b; 
string s1,s2;
int p1,p2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>s1>>b>>s2;
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b)
	{
		cout<<"1";
		if(p1==p2)
		{
			cout<<"1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
			{
				cout<<"1";
				if((s1[2]<='C'&&s2[2]<='C'&&abs(s1[2]-s2[2])==1)||(s1[2]>='D'&&s2[2]>='D'))
					cout<<"1";
				else
					cout<<"0";
			}	
			else
				cout<<"00";
		}
		else
			cout<<"000";	
	}
	else
		cout<<"0000";
	return 0;
} 
