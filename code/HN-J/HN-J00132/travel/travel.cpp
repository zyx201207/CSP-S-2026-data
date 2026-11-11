#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans=""; 
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
			{
				if(abs(int(s1[2])-int(s2[2]))==1)
				{
					ans="1111";
				}
				else{
					ans="1110";
				}
			}
			else{
				ans="1100";
			}
		}
		else{
			ans="1000";
		}
	}
	else {
		ans="0000";
	}
	cout<<ans;
	return 0;
 } 
