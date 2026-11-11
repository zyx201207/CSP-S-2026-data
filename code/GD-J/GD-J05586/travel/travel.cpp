#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+='1';
		ll su=(s1[0]-'0')*10+(s1[1]-'0'),sd=(s2[0]-'0')*10+(s2[1]-'0');
		if(sd==su)
		{
			ans+='1';
			if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D'))
			{
				ans+='1';
				ll ad=max(s1[2]-'A',s2[2]-'A'),as=min(s1[2]-'A',s2[2]-'A');
				if(as+1==ad)
					ans+='1';
				else
					ans+='0'; 
			}
			else
				ans+="00";
		}
		else
			ans+="000";
	}
	else	
		ans="0000";
	cout<<ans;
	return 0;
 } 
