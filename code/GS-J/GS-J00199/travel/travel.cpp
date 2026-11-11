#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

string c1,s1,c2,s2;
int p1,p2;
char x1,x2;
bool f,f1,f2,f3,f4;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		f1=1;
		p1=(s1[0]-'0')*10+(s1[1]-'0');
		p2=(s2[0]-'0')*10+(s2[1]-'0');
		x1=s1[2];
		x2=s2[2];
		if(p1==p2)
		{
			f2=1;
			if(x1=='A'||x1=='B'||x1=='C')
			{
				if(x2=='A'||x2=='B'||x2=='C')
				{
					f=1;
				}
			}
			if(x1=='D'||x1=='E')
			{
				if(x2=='D'||x2=='E')
				{
					f=1;
				}
			}
			if(f)
			{
				f3=1;
				p1=x1-'A';
				p2=x2-'A';
				if(p1-p2==1||p2-p1==1)
				{
					f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
