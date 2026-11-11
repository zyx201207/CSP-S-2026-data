#include<bits/stdc++.h>
using namespace std;
int cx=0,p=0,r,x,tc = 0,xl = 0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> c2 >>s1 >> s2;
	if(c1==s1)
	{
		cx=1;
		cout << "1";
	 } 
	 else
	 {
	 	cout << "0";
	 }
	if(cx == 1&&c2[0]==s2[0]&&c2[1]==s2[1])
	{
		p = 1;
		cout << "1";
	}
	else
	{
		cout << "0";
	}
    if(c2[2]=='A'||c2[2] == 'B'||c2[2] == 'C')
    {
    	r =1;
	}
	else
	{
		r =0;
	}
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
    {
    	x = 1;
	}
	else
	{
		x = 0;
	}
	if(r ==x&&p==1)
	{
		tc =1;
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if(c2[2] == 'A'&&s2[2] =='B')
	{
		xl = 1;
	}
	else if(c2[2] == 'B'&&s2[2] =='A'||s2[2] =='C')
	{
		xl = 1;
	}
    else if(c2[2] == 'C'&&s2[2] =='B')
	{
		xl = 1;
	}
    else if(c2[2] == 'D'&&s2[2] =='F')
	{
		xl = 1;
	}
	else if(c2[2] == 'F'&&s2[2] =='D')
	{
		xl = 1;
	}
	else
	{
		xl =0;
	}
	if(xl == 1&& tc ==1)
	{
		cout <<"1";
	}
	else
	{
		cout << "0";
	}
 } 
