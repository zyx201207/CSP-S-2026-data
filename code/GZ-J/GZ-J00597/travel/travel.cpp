//GZ-J00597 六盘水市第二十四中学 王轩宇
#include<bits/stdc++.h>
using namespace std;
int pp(int x)
{
	if(x<0)
	{
		x=x-x-x;
	}
	return x;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c,e;
	char b[7],d[7];
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++)
	{
		if(b[i]!=d[i])
		{
			cout<<"1000";
			return 0;
		}
	}
	if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))
	{
		cout<<"1111";
		return 0;
	}
	else
	{
		e=b[2]-d[2];
		if(pp(e)<=2&&b[2]!='D'&&b[2]!='F'&&d[2]!='D'&&d[2]!='F')
		{
			if(pp(e)==1)
			{
				cout<<"1111";
				return 0;
			}
			else
			{
				cout<<"1110";
				return 0;
			}
		}
		else
		{
			cout<<"1100";
			return 0;
		}
	}
	return 0;
}
