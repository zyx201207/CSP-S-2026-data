#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans="0000";
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans[0]='1';	
		int a=(s1[0]-'0')*10+s1[1]-'0';
		int b=(s2[0]-'0')*10+s2[1]-'0';
		if(a==b)
		{
			ans[1]='1';
			int c=s1[2]-'A'+1,d=s2[2]-'A'+1;
			if((c<=3&&d<=3)||(c>3&&d>3))
			{
				ans[2]='1';
				if(abs(c-d)==1)
				{
					if(c==3||d==3)
					{	
						if(c==3)
							if(d!=4)
								ans[3]='1';
						if(d==3)
							if(c!=4)
								ans[3]='1';
					}
					else 
					{
						ans[3]='1';
					}	
				}			
			}
		}						
	}
	cout<<ans;	
	return 0;
}

