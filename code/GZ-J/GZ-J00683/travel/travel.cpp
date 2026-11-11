//GZ-J00683 遵义市第十二中学 兰至立 
#include<bits/stdc++.h>
using namespace std;
int f(string x,string y)
{
	for(int i=0;i<2;i++)
	{
		if(x[i]!=y[i])
		{
			return 0;
		}
	}
	return 1;
}
int g(string o,string p)
{
	if((o[2]=='A'||o[2]=='B'||o[2]=='C')&&(p[2]=='A'||p[2]=='B'||p[2]=='C'))
	{
		return 1;
	}
	if((o[2]=='D'||o[2]=='F')&&(p[2]=='D'||p[2]=='F'))
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
			if(f(b,d))
	{
		cout<<'1';
		if(g(b,d))
		{
			cout<<'1';
			if(b[2]-1==d[2]||b[2]+1==d[2])
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
		else
		{
			cout<<"00"; 
		}
	}
	else
	{
		cout<<"000";
	 } 
	}
	else
	{
		cout<<"0000";
	} 
	return 0;
}
