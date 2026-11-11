#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else 
	{
		string r,x;
		char a,b;
		r=s1[0]+s1[1];
		x=s2[0]+s2[1];
		if(x!=r) cout<<"1000";
		else
		{
			a=s1[2],b=s2[2];
			if(a<='C'&&b<='C')
			{
				if(a==b+1||b==a+1) cout<<"1111";
				else cout<<"1110";
			}
			else if(a>='D'&&b>='D')
			{
				if(a==b+1||b==a+1) cout<<"1111";
				else cout<<"1110"; 
			}
			else cout<<"1100";
		}
	}
	return 0;
} 
