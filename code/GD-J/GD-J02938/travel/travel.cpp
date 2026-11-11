#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool f1,f2,f3,f4;
int a,b,e,f;
char c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		f1=1;
		a=(s1[0]-'0')*10+s1[1]-'0';
		b=(s2[0]-'0')*10+s2[1]-'0';
		if(a==b)
		{
			f2=1;
			c=s1[2],d=s2[2];
			if(('A'<=c&&c<='C'&&'A'<=d&&d<='C')||('D'<=c&&c<='E'&&'D'<=d&&d<='E'))
			{
				f3=1;
				e=c-'A',f=d-'A';
				if((e-f)==1||(e-f)==-1)
				{
					f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);
	fclose(stdout);
} 
