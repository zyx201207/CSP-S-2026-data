#include<bits/stdc++.h>
using namespace std;
#define toN(a,b) ((a-48)*10+(b-48))
#define toN1(a) (a-48)
string a="ABC",b="DE";
int main(void)
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(toN(s1[0],s1[1])==toN(s2[0],s2[1]))
		{
			cout<<1;
			if(a.find(s1[2])!=string::npos && a.find(s2[2])!=string::npos
			|| b.find(s1[2])!=string::npos && b.find(s2[2])!=string::npos)
			{
				cout<<1;
				if(abs(s1[2]-s2[2])==1)cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	return 0;
}