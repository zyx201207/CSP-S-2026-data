#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2;
char s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a1>>s1>>c2>>a2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(a1==a2)
		{
			cout<<"1";
			if((s1<='C'&&s2<='C')||s1>'C'&&s2>'C')
			{
				cout<<"1";
				if(abs(s1-s2)<2||(s1>'C'&&s2>'C')) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
