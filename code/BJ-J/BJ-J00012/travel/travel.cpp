#include <bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	bool ans1, ans2, ans3, ans4;
	ans1=ans2=ans3=ans4=0;
	if(c1==c3)
	{
		ans1=1;
    	int x, y;
	    x=(c2[0]-'0')*10+c2[1]-'0';
    	y=(c4[0]-'0')*10+c4[1]-'0';
    	if(x==y)
	    {
		    ans2=1;
		    if(c2[2]>='D'&&c4[2]>='D')
	        {
		        ans3=1;
		        ans4=1;
	        }
	        if(c2[2]<='C'&&c4[2]<='C')
	        {
		        ans3=1;
		        if(abs(c2[2]-c4[2])==1)
		        {
			        ans4=1;
		        }
	        }
	    }
	}
	string s;
	if(ans1==1)
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	if(ans2==1)
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	if(ans3==1)
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	if(ans4==1)
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	cout<<s;
	return 0;
}
