#include <bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
bool c[5]={0};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2)
	{
		c[1]=1;
		if(b1[0]==b2[0]&&b1[1]==b2[1])
		{
			c[2]=1;
			if((b1[2]>='A'&&b1[2]<='C'&&b2[2]>='A'&&b2[2]<='C'&&b2[2]!=b1[2])||(b1[2]>='D'&&b1[2]<='F'&&b2[2]>='D'&&b2[2]<='F'&&b2[2]!=b1[2]))
			{
				c[3]=1;
				if(b1[2]+1==b2[2])c[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)
		cout<<c[i];
	return 0;
}
