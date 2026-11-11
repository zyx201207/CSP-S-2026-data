#include<bits/stdc++.h>
using namespace std;
int pd(char o)
{
	if(o=='A'||o=='B'||o=='C')
	{
		return 1;
	}
	return 2;
}
bool pd2(char o,char p)
{
	if(abs(o-p)==1)
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
	int q=0,w=0,e=0,r=0;
	char zw1=b[2],zw2=d[2];
	int p1=(b[0]-'0')*10+b[1]-'0',p2=(d[0]-'0')*10+d[1]-'0';
	if(a==c)
	{
		q=1;
		if(p1==p2)
		{
			w=1;
			if(pd(zw1)==pd(zw2))
			{
				e=1;
				if(pd2(zw1,zw2))
				{
					r=1;
				}
			}
		 } 
	}
	cout<<q<<w<<e<<r; 
	return 0;
}

