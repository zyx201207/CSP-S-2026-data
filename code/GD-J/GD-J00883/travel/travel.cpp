#include <bits/stdc++.h>
using namespace std;
char a,b;
int c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1==c2)
	{
		cout<<1;
		if(s1==s2)
		{
			cout<<1;
			if((a<='C'&&b<='C')||(a>='D'&&b>='D'))
			{
				cout<<1;
				if(abs(a-b)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
 } 
