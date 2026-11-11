//GZ-J00296，贵阳市南明区李端棻中学，任柏翰 
#include<bits/stdc++.h>
using namespace std; 

string c1,s1,c2,s2;  
string ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
		ans="0000";
	else
	{
		ans+='1';
		bool ok=true;
		for(int i=0;i<=1;i++)
		{
			if(s1[i]!=s2[i])
			{
				ok=false;
				break;
			}
		}
		ans+=(ok?'1':'0');
		if(!ok)
		{
			ans+='0';
			ans+='0';
		}
		else
		{
			if(s1[2]>='D' && s2[2]>='D')
			{
				ans+='1';
				ans+='1';
			}
			else if(s1[2]<='C' && s2[2]<='C')
			{
				ans+='1';
				if(abs(s1[2]-s2[2])==1)
					ans+='1';
				else
					ans+='0';
			}
			else
			{
				ans+='0';
				ans+='0';
			}
		}
	}
	cout<<ans;
	
	return 0;
}
