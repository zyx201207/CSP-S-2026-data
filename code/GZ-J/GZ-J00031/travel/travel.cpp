//GZ-J00031 贵阳市白云区华师一学校 李峈颐 
#include<bits/stdc++.h>
using namespace std;
int s1,s2,c1,c2;
char ca1,ca2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>ca1>>s2>>c2>>ca2;
	if(s1==s2)
	{
		cout<<1;
		if(c1==c2)
		{
			cout<<1;
			if((ca1<='C'&&ca1>='A'&&ca2<='C'&&ca2>='A')||(ca1<='F'&&ca1>='D'&&ca2<='F'&&ca2>='D'))
			{
				cout<<1;
				if((char(ca1+1)==ca2||char(ca1-1)==ca2)||(ca1=='D'&&ca2=='F')||(ca1=='F'&&ca2=='D'))
				{
					cout<<1;
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";	
			}
		}
		else
		{
			cout<<"000";	
		}
	}
	else
	{
		cout<<"0000";	
	}
	
	
	return 0;
 } 
