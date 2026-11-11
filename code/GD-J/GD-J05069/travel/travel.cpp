#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	int a1,a2;
	cin>>a1>>c1>>a2>>c2;
	string ans="";
	if(a1==a2)
	{
		ans+="1";
		if(c1[0]==c2[0]&&c1[1]==c2[1])
		{
			ans+="1";
			if(c1[2]<'D'&&c2[2]<'D'||c1[2]>'C'&&c2[2]>'C')
			{
				ans+="1";
				if(c1[2]=='C'&&c2[2]=='A'||c1[2]=='A'&&c2[2]=='C')ans+="0";
				else ans+="1";
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
} 
