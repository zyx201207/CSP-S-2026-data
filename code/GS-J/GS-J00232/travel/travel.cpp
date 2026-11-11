#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,s1="",s2="";
	cin>>a>>b;
	s1+=a+b;
	cin>>a>>b;
	s2+=a+b;
	if(s1[0]==s2[0] && s1[1]==s2[1])
	{
		cout<<"1";
		if(s1[2]==s2[2] && s1[3]==s2[3])
		{
			cout<<"1";
			if( ( (s1[4]>='A' && s1[4]<='C') && (s2[4]>='A' && s2[4]<='C') ) || ( (s1[4]>='D' && s1[4]<='F') && (s2[4]>='D' && s2[4]<='F') ) )
			{
				cout<<"1";
				if(s1[4]-s2[4]==1 || s1[4]-s2[4]==-1)
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
