#include <bits/stdc++.h>
using namespace std;
int a[10];
string c1,s1;
string c2,s2;
int foo(char x)
{
	if(x=='A'||x=='B'||x=='C')return 1;
	else return 2;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1==c2)
	{
		a[1]=1;
		if((s1[0]==s2[0])&&(s1[1]==s2[1]))
		{
			a[2]=1;
			int cnt1=foo(s1[2]),cnt2=foo(s2[2]);
			if(cnt1==cnt2)
		    {
			   a[3]=1;
			   if(cnt1==2)a[4]=1;
			   else 
			   {
			   	    if(abs((s1[2]-'A')-(s2[2]-'A'))==1)a[4]=1;
			   }
		    }
		}
	}
	for(int i=1;i<=4;i++)cout<<a[i];
	return 0;
}
 
