#include <bits/stdc++.h>
using namespace std;
char ans[4]={'0','0','0','0'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans[0]='1';
		if(s1[0]==s2[0] and s1[1]==s2[1])
		{
			ans[1]='1';
			if(s1[2] <='C' and s2[2] <='C')
			{
				ans[2]='1';
				if(s1[2]-s2[2]==1 or s1[2]-s2[2]==-1)
					ans[3]='1';
			}
			else if((s1[2]=='D' and  s2[2] =='F') or (s2[2]=='D' and  s1[2] =='F'))
			{
				ans[2]='1';
				ans[3]='1';
			}
		}
	}
	for(int i=0;i<=3;i++)
		cout<<ans[i];
	return 0;
}
