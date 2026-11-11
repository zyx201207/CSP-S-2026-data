#include <bits/stdc++.h>
using namespace std;
int c1;
int c2;
int a=0;
string s1;
string s2;
string b;
string c;
string d;
string e;
string f;
string g;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	b=s1[0];
	c=s1[1];
	d=s1[2];
	e=s2[0];
	f=s2[1];
	g=s2[2];
	if(c1==c2)
	{
		a+=1000;
	}
	if(b==e)
	{
		if(c==d)
		{
		    a+=100;
		}
	}
	if(d>="A"&&d<="C")
	{
		if(g>="A"&&g<="C")
		{
			a+=10;
			if(d=="B"||g=="B")
	        {
		        a+=1;
            }
        }
	}
	else if(d=="D"||d=="F")
	{
		if(g=="D"||g=="F")
		{
			a+=11;
		}
	}
	cout<<a;
	return 0;
}
