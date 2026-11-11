#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+='1';
		if(s1[0]==s2[0] and s1[1]==s2[1])
		{
			ans+='1';
			if(s1[2]=='D' and s2[2]=='F')
			{
				ans+="11";
			}else if(s1[2]<68 and s2[2]<68){
				ans+='1';
				if(s1[2]==s2[2]+1 or s1[2]==s2[2]-1)
				{
					ans+='1';
				}else{
					ans+='0';
				}
			}else{
				ans+="00";
			}	
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	cout<<ans;
    return 0;
}


