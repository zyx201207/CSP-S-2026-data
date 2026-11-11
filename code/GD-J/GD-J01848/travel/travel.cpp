#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		string x=s1.substr(0,2),y=s2.substr(0,2);
		if(x==y)
		{
			cout<<'1';
			char cx=s1[2],cy=s2[2];
			if(!((cx<='C'&&cy>='D')||(cx>='D'&&cy<='C')))
			{
				cout<<'1';
				if(abs((int)cx-(int)cy)==1) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
