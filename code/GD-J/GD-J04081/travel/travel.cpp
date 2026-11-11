#include<bits/stdc++.h>
using namespace std;
string t1,t2,t3,t4;
int a1,a2,b1,b2;
char c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>t1>>t2>>t3>>t4;
	a1=(t1[0]-'0')*10+(t1[1]-'0');
	a2=(t3[0]-'0')*10+(t3[1]-'0');
	b1=(t2[0]-'0')*10+(t2[1]-'0');
	b2=(t4[0]-'0')*10+(t4[1]-'0');
	c1=t2[2];
	c2=t4[2];
	if(a1==a2)
	{
		cout<<"1";
		if(b1==b2)
		{
			cout<<"1";
			if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D'))
			{
				cout<<"1";
				if(c1>c2)
				{
					swap(c1,c2);
				}
				if((c1<='C'&&c2<='C'&&c2-c1==1)||(c1>='D'&&c2>='D'))
				{
					cout<<"1";
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
