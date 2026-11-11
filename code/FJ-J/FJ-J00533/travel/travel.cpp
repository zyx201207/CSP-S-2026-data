#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2;
string s1,s2;
bool fa,fb,fc;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		a1=(s1[0]-'0')*10+(s1[1]-'0');
		a2=(s2[0]-'0')*10+(s2[1]-'0');
		if(a1==a2)
		{
			cout<<"1";
			fa='A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C';
			fb='D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F';
			if(fa||fb)
			{
				cout<<"1";
				if(abs(s1[2]-s2[2])==1)
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
