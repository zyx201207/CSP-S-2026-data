#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2) 
	{
		cout<<"0"<<"0"<<"0"<<"0";		
	}
	else 
	{
		cout<<"1";
		if(c1[0]*10+c1[1]==c2[0]*10+c2[1])
		{
			cout<<"1";
			if((c1[2]<='C'&&c2[2]<='C')||(c1[2]>'C'&&c2[2]>'C'))
			{
				cout<<"1";
				if(c1[2]>'C') cout<<"1";
				else if(c1[2]+1==c2[2]||c1[1]-1==c2[2])	cout<<"1";
				else cout<<"0";
			}
			else cout<<"0"<<"0";
		} 
		else
		{
			cout<<"0"<<"0"<<"0";
		} 	
	}
	return 0;
}
