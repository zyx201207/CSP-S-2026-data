#include <bits/stdc++.h>
using namespace std;
string c1,c2;
int s1,s2;
char ss1,ss2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1==s2)
		{
			cout<<"1";
			if((ss1<='C' && ss2<='C') || (ss1>='D' && ss2>='D'))
			{
				cout<<"1";
				if(ss1==ss2+1 || ss1==ss2-1)
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
