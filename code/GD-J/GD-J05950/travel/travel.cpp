#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			if(s1[2]>'C'&&s2[2]>'C'||s1[2]<='C'&&s2[2]<='C')
			{
				if(s1[2]==s2[2]+1||s1[2]+1==s2[2])
				{
					cout<<1111;
				}
				else
				{
					cout<<1110;
				}
			}
			else
			{
				cout<<1100;
			}
		}
		else
		{
			cout<<1000;
		}
	}
	return 0;
}
