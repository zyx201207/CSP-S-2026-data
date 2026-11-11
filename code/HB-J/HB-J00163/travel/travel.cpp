#include <bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int flag[4];
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		flag[0]=1;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			flag[1]=1;
			int book1=0;
			int book2=0;
			book1=(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')?0:1;
			//zuo0 you1
			book2=(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')?0:1;
			if(book1==book2)
			{
				flag[2]=1;
				if(abs((s1[2]-'0')-(s2[2]-'0'))==1)
				{
					flag[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		cout<<flag[i];
	}
	return 0;
}
