#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool b1,b2,b3,b4;
void f(char a,char b)
{
	if(a>b) swap(a,b);
	if(a=='D'&&b=='F')
		b3=b4=1;
	else if(a=='A')
	{
		switch(b)
		{
			case 'B':b3=b4=1;break;
			case 'C':b3=1;
		}
	}
	else if(a=='B'&&b=='C')
		b3=b4=1;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		b1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			b2=1;
			f(s1[2],s2[2]);
		}
	 } 
	cout<<b1<<b2<<b3<<b4;
	return 0;	
}
