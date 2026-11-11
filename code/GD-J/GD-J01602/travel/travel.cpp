#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,w=0,x=0,y=0,z=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		w=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			x=1;
			if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C'))
			{
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
				{
					y=1;
				}else
				{
					y=1;
					z=1;
				}
			}
		}
	}
	cout<<w<<x<<y<<z<<endl;
	return 0;
}
