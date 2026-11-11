#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2)
	{   
		cout<<'1';
		int a=(s1[0]-'0')*10+s1[1]-'0';
		int b=(s2[0]-'0')*10+s2[1]-'0';
		if(a==b)
		{
			cout<<'1';
			char as=s1[2],bs=s2[2];
			if((as>='D'&&bs>='D')||(as<='C'&&bs<='C'))
			{
				cout<<'1';
				if((abs(as-bs)==1||(as=='D'&&bs=='F')||(as=='F'&&bs=='D')))cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
