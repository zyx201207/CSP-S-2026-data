#include<bits/stdc++.h>
using namespace std;
string s,v,s1,v1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>v>>s1>>v1;
	if(s[0]==s1[0]&&s[1]==s1[1])
	{
		cout<<1;
		if(v[0]==v1[0]&&v[1]==v1[1])
		{
			cout<<1;
			if(v[2]<='C'&&v[2]>='A'&&v1[2]<='C'&&v1[2]>='A'||v[2]<='F'&&v[2]>='D'&&v1[2]<='F'&&v1[2]>='D')
			{
				cout<<1;
				if(v[2]-'A'+1==v1[2]-'A'||v1[2]-'A'+1==v[2]-'A')
					cout<<1;
				else
					cout<<0;
			}
			else 
				cout<<0<<0;	
		}
		else
			cout<<0<<0<<0;		
	}	
	else
		cout<<0<<0<<0<<0;
	
	return 0;
}
