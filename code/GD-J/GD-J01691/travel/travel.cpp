#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[5]={0};
int k1,k2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			a[2]=1;
			k1=(int)(s1[2]-'A')+1;
			k2=(int)(s2[2]-'A')+1;
			if((k1<=3&&k2<=3)||(k1>=4&&k2>=4))
			{
				a[3]=1;
				if(k1-k2==1||k1-k2==-1)
				{
					a[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
