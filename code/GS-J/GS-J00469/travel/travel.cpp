#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r"stdin);
	freopen("travel.out","w"stdout);
	long long c1,c2,a,b,c,d;
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
		if(c1=c2)
		{
			    a=1;
				b=1;
		}	
		else
			{
				a=0;
				b=0;
	        }
			if(s1/10%10==s2/10%10)
			{
				c=1;
				d=1;
			}
			else
			{
				c=0;
				d=0;
			}
					
	cout<<a<<b<<c<<d;
    return 0;
}
