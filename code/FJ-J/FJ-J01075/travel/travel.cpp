#include<bits/stdc++.h>
using namespace std;
typedef long long inf;
string c1,s1,c2,s2;
int a=1,b=1,c=1,d=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])a=0;
	}
	if(a)
	{
		for(int i=0;i<=1;i++)
		{
			if(s1[i]!=s2[i])b=0;
		}
		if(b)
		{
			int m1=s1[2],m2=s2[2];
			if(m1<='C' and m2>='D' or m1>='D' and m2<='C')
			{
				c=0;d=0;
			}
			else{
				if(m1=='A' and m2=='C' or m2=='A'  and m1=='C')d=0;
			}
		}
		else 
		{
			c=0;d=0;
		}
	}
	else{
		b=0;c=0;d=0;
	}
	printf("%d%d%d%d",a,b,c,d);
	return 0;
}

